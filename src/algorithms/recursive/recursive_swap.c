void swap(int* a, int* b) {                           // swap two values
    int n1 = *a;
    *a = *b;
    *b = n1;
}

void generate_swap(int arr[], int n,
    void (*callback)(int perm[], int n), int pos) {   // in-place generation
    if (pos == n) {                                   // permutation ready
        callback(arr, n);                             // output result
        return;
    }
    
    for (int i = pos; i < n; i++) {                   // fix position pos
        swap(&arr[pos], &arr[i]);                     // choose element
        generate_swap(arr, n, callback, pos + 1);     // recurse
        swap(&arr[i], &arr[pos]);                     // restore array
    }
}

void permutations_recursive_swap(int arr[], int n,
    void (*callback)(int perm[], int n)) {            // wrapper for swap algo
    if (n <= 0 || arr == NULL)                        // input check
        return;

    generate_swap(arr, n, callback, 0);               // start recursion
}