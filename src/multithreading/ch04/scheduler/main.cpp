#include <iostream>

#include "dispatcher.hpp"
#include "request.hpp"

#include <chrono>
#include <csignal>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

std::sig_atomic_t signal_caught = 0;
std::mutex log_mutex;

void sigint_handler(const int sig) { signal_caught = 1; }

void log(std::unique_ptr<std::string> text) {
  std::unique_lock<std::mutex> lock(log_mutex);
  std::cout << text->data() << std::endl;
}

int main(int argc, char *argv[]) {

  signal(SIGINT, &sigint_handler);

  Dispatcher::init(10);

  std::cout << "Initialised." << std::endl;

  int cycles = 0;

  while (!signal_caught && cycles < 50) {
    std::unique_ptr<Request> request = std::make_unique<Request>();
    request->setValue(cycles);
    request->setOutput(&log);
    Dispatcher::addRequest(std::move(request));
    cycles++;
  }

  std::this_thread::sleep_for(std::chrono::seconds(2));
  Dispatcher::stop();

  std::cout << "Clean-up." << std::endl;

  return 0;
}
