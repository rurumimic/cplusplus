# Install

## with Package Manager

### Ubuntu

#### prerequisites

install dependencies:

```bash
sudo apt install -y gpg-agent wget
```

add the repo:

```bash
wget -O- https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB | gpg --dearmor | sudo tee /usr/share/keyrings/oneapi-archive-keyring.gpg > /dev/null
```

add the signed entry:

```bash
echo "deb [signed-by=/usr/share/keyrings/oneapi-archive-keyring.gpg] https://apt.repos.intel.com/oneapi all main" | sudo tee /etc/apt/sources.list.d/oneAPI.list
```

update:

```bash
sudo apt update
```

#### Install Intel OneAPI TBB Devel

```bash
sudo apt install intel-oneapi-tbb-devel
```

## from Source

- uxlfoundation/oneTBB: [INSTALL.md](https://github.com/uxlfoundation/oneTBB/blob/master/INSTALL.md)

```bash
git clone https://github.com/uxlfoundation/oneTBB.git
cd oneTBB
```

### Build

```bash
mkdir build dist
```

configure:

```bash
cmake -DCMAKE_INSTALL_PREFIX=$PWD/dist -DTBB_TEST=OFF -B build -S .
```

build:

```bash
cmake --build build
```

install:

```bash
cmake --install build
```

<details>
    <summary>target</summary>

```bash
dist
├── include
│   ├── oneapi
│   │   ├── tbb
│   │   │   ├── blocked_nd_range.h
│   │   │   ├── blocked_range2d.h
│   │   │   ├── blocked_range3d.h
│   │   │   ├── blocked_range.h
│   │   │   ├── cache_aligned_allocator.h
│   │   │   ├── collaborative_call_once.h
│   │   │   ├── combinable.h
│   │   │   ├── concurrent_hash_map.h
│   │   │   ├── concurrent_lru_cache.h
│   │   │   ├── concurrent_map.h
│   │   │   ├── concurrent_priority_queue.h
│   │   │   ├── concurrent_queue.h
│   │   │   ├── concurrent_set.h
│   │   │   ├── concurrent_unordered_map.h
│   │   │   ├── concurrent_unordered_set.h
│   │   │   ├── concurrent_vector.h
│   │   │   ├── detail
│   │   │   │   ├── _aggregator.h
│   │   │   │   ├── _aligned_space.h
│   │   │   │   ├── _allocator_traits.h
│   │   │   │   ├── _assert.h
│   │   │   │   ├── _attach.h
│   │   │   │   ├── _concurrent_queue_base.h
│   │   │   │   ├── _concurrent_skip_list.h
│   │   │   │   ├── _concurrent_unordered_base.h
│   │   │   │   ├── _config.h
│   │   │   │   ├── _containers_helpers.h
│   │   │   │   ├── _exception.h
│   │   │   │   ├── _export.h
│   │   │   │   ├── _flow_graph_body_impl.h
│   │   │   │   ├── _flow_graph_cache_impl.h
│   │   │   │   ├── _flow_graph_impl.h
│   │   │   │   ├── _flow_graph_indexer_impl.h
│   │   │   │   ├── _flow_graph_item_buffer_impl.h
│   │   │   │   ├── _flow_graph_join_impl.h
│   │   │   │   ├── _flow_graph_node_impl.h
│   │   │   │   ├── _flow_graph_nodes_deduction.h
│   │   │   │   ├── _flow_graph_node_set_impl.h
│   │   │   │   ├── _flow_graph_tagged_buffer_impl.h
│   │   │   │   ├── _flow_graph_trace_impl.h
│   │   │   │   ├── _flow_graph_types_impl.h
│   │   │   │   ├── _hash_compare.h
│   │   │   │   ├── _intrusive_list_node.h
│   │   │   │   ├── _machine.h
│   │   │   │   ├── _mutex_common.h
│   │   │   │   ├── _namespace_injection.h
│   │   │   │   ├── _node_handle.h
│   │   │   │   ├── _pipeline_filters_deduction.h
│   │   │   │   ├── _pipeline_filters.h
│   │   │   │   ├── _range_common.h
│   │   │   │   ├── _rtm_mutex.h
│   │   │   │   ├── _rtm_rw_mutex.h
│   │   │   │   ├── _scoped_lock.h
│   │   │   │   ├── _segment_table.h
│   │   │   │   ├── _small_object_pool.h
│   │   │   │   ├── _string_resource.h
│   │   │   │   ├── _task.h
│   │   │   │   ├── _task_handle.h
│   │   │   │   ├── _template_helpers.h
│   │   │   │   ├── _utils.h
│   │   │   │   └── _waitable_atomic.h
│   │   │   ├── enumerable_thread_specific.h
│   │   │   ├── flow_graph_abstractions.h
│   │   │   ├── flow_graph.h
│   │   │   ├── global_control.h
│   │   │   ├── info.h
│   │   │   ├── memory_pool.h
│   │   │   ├── mutex.h
│   │   │   ├── null_mutex.h
│   │   │   ├── null_rw_mutex.h
│   │   │   ├── parallel_for_each.h
│   │   │   ├── parallel_for.h
│   │   │   ├── parallel_invoke.h
│   │   │   ├── parallel_pipeline.h
│   │   │   ├── parallel_reduce.h
│   │   │   ├── parallel_scan.h
│   │   │   ├── parallel_sort.h
│   │   │   ├── partitioner.h
│   │   │   ├── profiling.h
│   │   │   ├── queuing_mutex.h
│   │   │   ├── queuing_rw_mutex.h
│   │   │   ├── rw_mutex.h
│   │   │   ├── scalable_allocator.h
│   │   │   ├── spin_mutex.h
│   │   │   ├── spin_rw_mutex.h
│   │   │   ├── task_arena.h
│   │   │   ├── task_group.h
│   │   │   ├── task.h
│   │   │   ├── task_scheduler_observer.h
│   │   │   ├── tbb_allocator.h
│   │   │   ├── tbbmalloc_proxy.h
│   │   │   ├── tick_count.h
│   │   │   └── version.h
│   │   └── tbb.h
│   └── tbb
│       ├── blocked_nd_range.h
│       ├── blocked_range2d.h
│       ├── blocked_range3d.h
│       ├── blocked_range.h
│       ├── cache_aligned_allocator.h
│       ├── collaborative_call_once.h
│       ├── combinable.h
│       ├── concurrent_hash_map.h
│       ├── concurrent_lru_cache.h
│       ├── concurrent_map.h
│       ├── concurrent_priority_queue.h
│       ├── concurrent_queue.h
│       ├── concurrent_set.h
│       ├── concurrent_unordered_map.h
│       ├── concurrent_unordered_set.h
│       ├── concurrent_vector.h
│       ├── enumerable_thread_specific.h
│       ├── flow_graph_abstractions.h
│       ├── flow_graph.h
│       ├── global_control.h
│       ├── info.h
│       ├── memory_pool.h
│       ├── mutex.h
│       ├── null_mutex.h
│       ├── null_rw_mutex.h
│       ├── parallel_for_each.h
│       ├── parallel_for.h
│       ├── parallel_invoke.h
│       ├── parallel_pipeline.h
│       ├── parallel_reduce.h
│       ├── parallel_scan.h
│       ├── parallel_sort.h
│       ├── partitioner.h
│       ├── profiling.h
│       ├── queuing_mutex.h
│       ├── queuing_rw_mutex.h
│       ├── rw_mutex.h
│       ├── scalable_allocator.h
│       ├── spin_mutex.h
│       ├── spin_rw_mutex.h
│       ├── task_arena.h
│       ├── task_group.h
│       ├── task.h
│       ├── task_scheduler_observer.h
│       ├── tbb_allocator.h
│       ├── tbb.h
│       ├── tbbmalloc_proxy.h
│       ├── tick_count.h
│       └── version.h
├── lib
│   ├── cmake
│   │   └── TBB
│   │       ├── TBBConfig.cmake
│   │       ├── TBBConfigVersion.cmake
│   │       ├── TBBTargets.cmake
│   │       └── TBBTargets-relwithdebinfo.cmake
│   ├── libtbbmalloc_proxy.so -> libtbbmalloc_proxy.so.2
│   ├── libtbbmalloc_proxy.so.2 -> libtbbmalloc_proxy.so.2.15
│   ├── libtbbmalloc_proxy.so.2.15
│   ├── libtbbmalloc.so -> libtbbmalloc.so.2
│   ├── libtbbmalloc.so.2 -> libtbbmalloc.so.2.15
│   ├── libtbbmalloc.so.2.15
│   ├── libtbb.so -> libtbb.so.12
│   ├── libtbb.so.12 -> libtbb.so.12.15
│   ├── libtbb.so.12.15
│   └── pkgconfig
│       └── tbb.pc
└── share
    └── doc
        └── TBB
            └── README.md

12 directories, 157 files
```

</details>

