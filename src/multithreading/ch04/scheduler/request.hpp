#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "abstract_request.hpp"
#include <memory>
#include <string>

class Request : public AbstractRequest {
public:
  Request();
  ~Request() = default;

  Request(const Request &) = delete;
  Request(Request &&) = delete;
  Request &operator=(const Request &) = delete;
  Request &operator=(Request &&) = delete;

public:
  void setValue(const int value) final;
  void process(const int thread_id) final;
  void finish(const int thread_id) final;

private:
  typedef void (*logger)(std::unique_ptr<std::string> text);

public:
  void setOutput(logger log);

private:
  int value;
  logger log;
};

#endif // REQUEST_HPP
