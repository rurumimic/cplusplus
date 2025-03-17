#include "block.hpp"
#include "index.hpp"
#include "return.hpp"
#include "sequence.hpp"

int main() {
  submit_index_lambda(true);
  submit_index_functor(false);
  submit_index_lambda_detached(false);
  submit_index_functor_detached(false);

  submit_block_lambda(false);
  submit_block_functor(false);
  submit_block_lambda_detached(false);
  submit_block_functor_detached(true);

  submit_block_sum();

  submit_sequence_factorial();

  return 0;
}
