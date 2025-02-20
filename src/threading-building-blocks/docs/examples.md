# Examples

- github: [examples](https://github.com/uxlfoundation/oneTBB/tree/master/examples/)

## Getting Started

- github: [getting_started](https://github.com/uxlfoundation/oneTBB/tree/master/examples/getting_started)

### sub_string_finder

- github: [sub_string_finder](https://github.com/uxlfoundation/oneTBB/tree/master/examples/getting_started/sub_string_finder)

```bash
cd oneTBB/examples/getting_started/sub_string_finder
```

#### Edit header

```cpp
#include "oneapi/tbb/parallel_for.h"
#include "oneapi/tbb/blocked_range.h"

#include "../../common/utility/utility.hpp"
```

#### Build sub_string_finder

```bash
cmake -S . -B Build
cd build
make sub_string_finder
```

#### Run sub_string_finder

```bash
sub_string_finder_simple
sub_string_finder_extended
sub_string_finder_pretty
```

