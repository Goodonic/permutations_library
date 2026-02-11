#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void generate(int arr[], int n, int current_perm[], int used[],
    void (*callback)(int perm[], int n), int pos) {  // backtracking generator
    
    if (pos == n) {                                  // full permutation built
        callback(current_perm, n);                   // call user function
        return;
    }
    
    for (int i = 0; i < n; i++) {                    // try all elements
        if (used[i] == 0) {                          // element not used
            current_perm[pos] = arr[i];              // place element
            used[i] = 1;                             // mark as used
            generate(arr, n, current_perm,
                used, callback, pos + 1);            // recurse deeper
            used[i] = 0;                             // backtrack
        }
    }
}

void permutations_backtrack(int arr[], int n,
    void (*callback)(int perm[], int n)) {            // classic backtracking
    if (n <= 0 || arr == NULL)                        // input check
        return;
    
    int* used = (int*)calloc(n, sizeof(int));         // used flags
    int* current_perm = (int*)malloc(n * sizeof(int));// current permutation
    
    generate(arr, n, current_perm, used, callback, 0);// start recursion
    
    free(used);                                       // free memory
    free(current_perm);
}