#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>

typedef struct value {
  int id;
  int value;
} t_value;

std::mutex values_mtx;
std::mutex cout_mtx;
std::vector<t_value> values;

/**
* mt19937 is a standard mersenne_twister_engine
* https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine
*/
int generate_random_value(const int& min, const int& max) {
  static thread_local std::mt19937 generator(std::hash<std::thread::id>()(std::this_thread::get_id()));
  std::uniform_int_distribution<int> distribution(min, max);
  return distribution(generator);
}

void task(int id) {
  // cout_mtx.lock();
  {
    std::lock_guard<std::mutex> cout_lock(cout_mtx);
    std::cout << "Thread " << id << " started." << std::endl;
  }
  // cout_mtx.unlock();

  // values_mtx.lock();
  int value;
  {
    std::lock_guard<std::mutex> values_lock(values_mtx);
    value = values[0].value;
  }
  // values_mtx.unlock();

  int random_value = generate_random_value(0, 10);
  value += random_value;

  {
    std::unique_lock<std::mutex> cout_lock(cout_mtx);
    std::cout << "Thread " << id << " add " << random_value << ". New vlue: " << value << std::endl;
  }

  {
    std::unique_lock<std::mutex> values_lock(values_mtx);
    values.push_back(t_value{id, value});
  }
}

int main (int argc, char *argv[]) {

  values.push_back(t_value{0, 42});

  std::vector<std::thread> threads;

  for (int i = 1; i <= 4; i++) {
    threads.push_back(std::thread(task, i));
  }

  for (auto& t : threads) {
    t.join();
  }

  for (const auto& value : values) {
    std::cout << "values[" << value.id << "] = " << value.value << std::endl;
  }

  return 0;
}

