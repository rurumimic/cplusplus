#include "request.hpp"

Request::Request() : value(0), log(nullptr) {}

void Request::setValue(const int value) { this->value = value; }

void Request::setOutput(logger log) { this->log = log; }

void Request::process(const int thread_id) {
  log(std::make_unique<std::string>("Request:  " + std::to_string(value) +
                                    " on thread " + std::to_string(thread_id)));
}

void Request::finish(const int thread_id) {
  log(std::make_unique<std::string>("Finished: " + std::to_string(value) +
                                    " on thread " + std::to_string(thread_id)));
}
