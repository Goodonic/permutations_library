//
// Created by orexo on 18.12.2025.
//

#ifndef RECURSIVE_ALGORITHMS_H

void permutations_backtrack(int arr[], int n, void (*callback)(int perm[], int n))


void permutations_recursive_swap(int arr[], int n, void (*callback)(int perm[], int n))


void permutations_recursive_lexicographic(int arr[], int n, void (*callback)(int perm[], int n));


void permutations_with_constraints(int arr[], int n,
    bool (*constraint)(int partial[], int k, int next_elem, void* data),
    void* constraint_data, void (*callback)(int perm[], int n));


void multiset_permutations(int arr[], int n, void (*callback)(int perm[], int n));

#define RECURSIVE_ALGORITHMS_H

#endif // RECURSIVE_ALGORITHMS_H
