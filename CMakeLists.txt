cmake_minimum_required(VERSION 3.30)
project(AlgorithmicCombinatoricsLab C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(LIB_SOURCES
        src/algorithms/core/adaptive.c
        src/algorithms/core/benchmark.c
        src/algorithms/core/iterator.c
        src/algorithms/core/testing.c
        src/algorithms/core/unified_interface.c
        src/algorithms/core/visualization.c
        src/algorithms/iterative/factorial_system.c
        src/algorithms/iterative/inversion_table.c
        src/algorithms/iterative/narayana.c
        src/algorithms/iterative/plus_one.c
        src/algorithms/iterative/reverse_narayana.c
        src/algorithms/optimized/binary_masks.c
        src/algorithms/optimized/cycle_leader.c
        src/algorithms/optimized/heap.c
        src/algorithms/optimized/johnson_trotter.c
        src/algorithms/optimized/minimal_change.c
        src/algorithms/optimized/pseudo_lexicographic.c
        src/algorithms/recursive/backtrack.c
        src/algorithms/recursive/constraints.c
        src/algorithms/recursive/lexicographic.c
        src/algorithms/recursive/multiset.c
        src/algorithms/recursive/recursive_swap.c
        src/core/memory_pool.c
        src/core/utils.c
        src/tests/correctness_tests.c
        src/tests/property_tests.c
        src/tests/stress_tests.c
        src/tests/unit_tests.c
)

set(LIB_HEADERS
        include/iterative_algorithms.h
        include/optimized_algorithms.h
        include/permutation_core.h
        include/permutation_types.h
        include/permutations.h
        include/recursive_algorithms.h
)

add_library(AlgorithmicCombinatoricsLab STATIC ${LIB_SOURCES} ${LIB_HEADERS})

target_include_directories(AlgorithmicCombinatoricsLab
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)