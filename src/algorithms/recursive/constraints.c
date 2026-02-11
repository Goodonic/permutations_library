#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int constraint_data[] = {1, 2, 1};                    // constraint parameters

bool constraint(int partial[], int k,
    int next_elem, void* constraint_data) {           // constraint checker
    int* l = (int*)constraint_data;
    int i = l[0];
    int j = l[1];
    int type = l[2];
    int check_i = 0;
    int check_j = 0;

    if (type == 0) {                                  // positional constraint
        if (next_elem == i && k == j)
            return false;
        else
            return true;
    }

    if (type == 1) {                                  // relative constraint
        for (int t = 0; t < k; t++) {
            if (partial[t] == i)
                check_i = 1;
            if (partial[t] == j)
                check_j = 1;
        }
        if (next_elem == i && check_j)
            return false;
        if (next_elem == j && !check_i)
            return false;
        return true;
    }

    return true;
}

void generate_with_constraints(int arr[], int n,
    int current_perm[], int used[],
    bool (*constraint)(int partial[], int k,
        int next_elem, void* data),
    void* constraint_data,
    void (*callback)(int perm[], int n), int pos) {   // constrained recursion
    if (pos == n) {                                   // full permutation
        callback(current_perm, n);                    // output
        return;
    }

    for (int i = 0; i < n; i++)
        if (used[i] == 0)
            if (constraint(current_perm, pos,
                arr[i], constraint_data)) {           // check constraint
                current_perm[pos] = arr[i];
                used[i] = 1;
                generate_with_constraints(arr, n,
                    current_perm, used, constraint,
                    constraint_data, callback,
                    pos + 1);                         // recurse
                used[i] = 0;                          // backtrack
            }
}

void permutations_with_constraints(int arr[], int n,
    bool (*constraint)(int partial[], int k,
        int next_elem, void* data),
    void* constraint_data,
    void (*callback)(int perm[], int n)) {            // constraint wrapper
    if (n <= 0 || arr == NULL)                        // input check
        return;

    int* used = (int*)calloc(n, sizeof(int));         // used flags
    int* current_perm = (int*)malloc(n * sizeof(int));// current permutation
    generate_with_constraints(arr, n, current_perm,
        used, constraint, constraint_data,
        callback, 0);                                 // start recursion
    
    free(used);                                       // free memory
    free(current_perm);
}