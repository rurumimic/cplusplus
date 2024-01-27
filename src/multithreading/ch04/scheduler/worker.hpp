#ifndef WORKER_HPP
#define WORKER_HPP

#include "abstract_request.hpp"

#include <condition_variable>
#include <mutex>

class Worker {
public:
  Worker() = delete;
  Worker(const int thread_id);

  ~Worker() = default;

  Worker(const Worker &) = delete;
  Worker(Worker &&) = delete;
  Worker &operator=(const Worker &) = delete;
  Worker &operator=(Worker &&) = delete;

private:
  int thread_id;
  std::condition_variable cv;
  std::mutex mtx;
  std::unique_lock<std::mutex> lock;
  std::unique_ptr<AbstractRequest> request;
  bool running;
  bool ready;

public:
  void run();
  void stop();
  void setRequest(std::unique_ptr<AbstractRequest> request);
  void getCondition(std::condition_variable *&cv); // reference to pointer
};

#endif // WORKER_HPP
