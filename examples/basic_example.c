#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void print_permutation(int perm[], int n) {          // print one permutation
    for (int i = 0; i < n; i++)
        printf("%d", perm[i]);                       // print element
    printf("\n");                                    // new line
}

int main() {
    int arr[] = {1, 2, 2};                            // input array
    int n = 3;
    int len = sizeof(arr) / sizeof(arr[0]);           // array length
    int constraint_data[] = { 1, 2, 1 };              // constraint parameters
    if (n <= len) {
        permutations_backtrack(arr, n,
            print_permutation);                       // backtracking
        printf("\n");
        permutations_recursive_swap(arr, n,
            print_permutation);                       // swap method
        printf("\n");
        permutations_recursive_lexicographic(arr, n,
            print_permutation);                       // lexicographic
        printf("\n");
        multiset_permutations(arr, n,
            print_permutation);                       // multiset
        printf("\n");
        permutations_with_constraints(arr, n,
            constraint, constraint_data,
            print_permutation);                       // constraints 
    }
}