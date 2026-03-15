#include "worker.hpp"
#include "dispatcher.hpp"
#include <chrono>
#include <memory>

Worker::Worker(const int thread_id)
    : thread_id(thread_id), lock(mtx, std::defer_lock), request(nullptr),
      running(true), ready(false) {}

void Worker::run() {
  while (running) {
    if (ready) {
      ready = false;
      request->process(thread_id);
      request->finish(thread_id);
    }

    if (Dispatcher::addWorker(this)) {
      // use the ready loop to deal with spurious wakeups
      while (!ready && running) {
        if (cv.wait_for(lock, std::chrono::seconds(1)) ==
            std::cv_status::timeout) {
          // timeout
        }
      }
    }
  }
}

void Worker::stop() { running = false; }

void Worker::setRequest(std::unique_ptr<AbstractRequest> request) {
  this->request = std::move(request);
  ready = true;
}

void Worker::getCondition(std::condition_variable *&cv) {
  cv = &this->cv; // update reference
}
