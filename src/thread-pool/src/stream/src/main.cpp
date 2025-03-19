#include "sequence.hpp"

int main() {
  std_cout_sequence();
  /*
   * --- std_cout_sequence ---
   * Task no. Task no. 1 executing.
   * 0 executing.
   * Task no. Task no. 23 executing.
   *  executing.
   * Task no. 4 executing.
   */

  sync_out_sequence();
  /*
   * --- sync_out_sequence ---
   * Task no. 0 executing.
   * Task no. 1 executing.
   * Task no. 2 executing.
   * Task no. 3 executing.
   * Task no. 4 executing.
   */

  flush_sequence();
  /*
   * --- flush_sequence ---
   * square root of  0 is 0.0000000000.
   * square root of  1 is 1.0000000000.
   * square root of  2 is 1.4142135624.
   * square root of  3 is 1.7320508076.
   * square root of  5 is 2.2360679775.
   * square root of  4 is 2.0000000000.
   * square root of  6 is 2.4494897428.
   * square root of  7 is 2.6457513111.
   * square root of  8 is 2.8284271247.
   * square root of  9 is 3.0000000000.
   * square root of 10 is 3.1622776602.
   * square root of 11 is 3.3166247904.
   * square root of 12 is 3.4641016151.
   * square root of 13 is 3.6055512755.
   * square root of 14 is 3.7416573868.
   * square root of 15 is 3.8729833462.
   */

  log_sequence();
  /*
   * --- log_sequence ---
   * Task no. 0 executing.
   * Task no. 2 executing.
   * Task no. 1 executing.
   * Task no. 4 executing.
   * Task no. 3 executing.
   * Task no. 5 executing.
   * Task no. 9 executing.
   * Task no. 7 executing.
   * Task no. 8 executing.
   * Task no. 6 executing.
   */

  return 0;
}
