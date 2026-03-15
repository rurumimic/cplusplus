#ifndef DISPATCHER_HPP
#define DISPATCHER_HPP

#include "abstract_request.hpp"
#include "worker.hpp"
#include <memory>
#include <queue>
#include <thread>
#include <vector>

class Dispatcher {
public:
  Dispatcher() = default;
  ~Dispatcher() = default;

  Dispatcher(const Dispatcher &) = delete;
  Dispatcher(Dispatcher &&) = delete;
  Dispatcher &operator=(const Dispatcher &) = delete;
  Dispatcher &operator=(Dispatcher &&) = delete;

public:
  static bool init(const int workers);
  static void stop();
  static void addRequest(std::unique_ptr<AbstractRequest> request);
  static bool addWorker(Worker *worker);

private:
  static std::queue<std::unique_ptr<AbstractRequest>> requests;
  static std::queue<Worker *> workers;
  static std::mutex requests_mtx;
  static std::mutex workers_mtx;
  static std::vector<std::unique_ptr<Worker>> all_workers;
  static std::vector<std::thread> all_threads;
};

#endif // DISPATCHER_HPP
