
#ifndef PERMUTATION_CORE_H
#define PERMUTATION_CORE_H
#ifdef __cplusplus
extern "C" {
#endif

    typedef enum {
        ALGO_BACKTRACK = 1,
        ALGO_RECURSIVE_SWAP,
        ALGO_NARAYANA,
        ALGO_FACTORIAL_SYSTEM,
        ALGO_JOHNSON_TROTTER,
        ALGO_HEAP,
        ALGO_MINIMAL_CHANGE,
        ALGO_CYCLE_LEADER,
        ALGO_BINARY_MASKS,
        ALGO_PSEUDO_LEXICOGRAPHIC
    } permutation_algorithm_t;

    typedef enum {
        PERM_SUCCESS = 0,
        PERM_ERROR_INVALID_ALGORITHM = -1,
        PERM_ERROR_INVALID_INPUT = -2,
        PERM_ERROR_INVALID_CALLBACK = -3,
        PERM_ERROR_MEMORY = -4,
        PERM_ERROR_EMPTY_ARRAY = -5
    } permutation_error_t;

    int generatePermutations(permutation_algorithm_t algo, int arr[], int n,
                             void (*callback)(int perm[], int n));

    void generatePermutationsAssert(permutation_algorithm_t algo, int arr[], int n,
                                    void (*callback)(int perm[], int n));

#ifdef __cplusplus
}
#endif

#endif
