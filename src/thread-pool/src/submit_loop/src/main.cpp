#include "block.hpp"
#include "index.hpp"

int main() {
  submit_index_lambda();
  submit_index_functor();
  submit_index_detached();

  submit_block_lambda();
  submit_block_functor();
  submit_block_detached();

  return 0;
}
