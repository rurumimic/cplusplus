#ifndef ABSTRACT_REQUEST_HPP
#define ABSTRACT_REQUEST_HPP

class AbstractRequest {
public:
  AbstractRequest() = default;
  virtual ~AbstractRequest() = default;

  AbstractRequest(const AbstractRequest &) = delete;
  AbstractRequest(AbstractRequest &&) = delete;
  AbstractRequest &operator=(const AbstractRequest &) = delete;
  AbstractRequest &operator=(AbstractRequest &&) = delete;

public:
  virtual void setValue(const int value) = 0;
  virtual void process(const int thread_id) = 0;
  virtual void finish(const int thread_id) = 0;
};

#endif // ABSTRACT_REQUEST_HPP
