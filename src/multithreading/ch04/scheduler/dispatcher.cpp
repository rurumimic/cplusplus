#include "dispatcher.hpp"

#include "abstract_request.hpp"
#include <condition_variable>
#include <iostream>

/**
 * static members are initialized only once when the program starts
 * static members are destroyed only once when the program ends
 * static members are shared by all objects of the class
 */
std::queue<std::unique_ptr<AbstractRequest>> Dispatcher::requests;
std::queue<Worker *> Dispatcher::workers;
std::mutex Dispatcher::requests_mtx;
std::mutex Dispatcher::workers_mtx;
std::vector<std::unique_ptr<Worker>> Dispatcher::all_workers;
std::vector<std::thread> Dispatcher::all_threads;

bool Dispatcher::init(const int workers) {
  for (int i = 0; i < workers; i++) {
    std::unique_ptr<Worker> worker = std::make_unique<Worker>(i);
    std::thread thread(&Worker::run, worker.get());

    all_workers.push_back(std::move(worker));
    all_threads.push_back(std::move(thread)); // thread is not copyable
  }

  return true;
}

void Dispatcher::stop() {

  for (auto &worker : all_workers) {
    worker->stop();
  }

  for (auto &thread : all_threads) {
    thread.join();
  }

}

void Dispatcher::addRequest(std::unique_ptr<AbstractRequest> request) {
  std::unique_lock<std::mutex> workers_lock(workers_mtx);

  if (workers.empty()) {
    workers_lock.unlock(); // deadlock avoidance!
    std::unique_lock<std::mutex> requests_lock(requests_mtx);
    requests.push(std::move(request));
    return;
  }

  Worker *worker = workers.front();
  worker->setRequest(std::move(request));

  std::condition_variable *cv;
  worker->getCondition(cv);
  cv->notify_one(); // notify the worker

  workers.pop(); // remove the worker from the queue until it is ready again
}

bool Dispatcher::addWorker(Worker *worker) {
  std::unique_lock<std::mutex> requests_lock(requests_mtx);

  if (requests.empty()) {
    requests_lock.unlock(); // deadlock avoidance!
    std::unique_lock<std::mutex> workers_lock(workers_mtx);
    workers.push(worker);
    return true;
  }

  std::unique_ptr<AbstractRequest> request = std::move(requests.front());
  worker->setRequest(std::move(request));
  requests.pop();

  return false;
}
