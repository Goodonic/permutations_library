int fact(int n) {                                     // factorial function
    int f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int num_unique_perms(int repeat[], int n, int u) {
    int c = fact(n);                                  // start with n!
    for (int i = 0; i < u; i++)
        c /= fact(repeat[i]);                         // divide by repeats
    return c;                                         // result count
}

void generate_multiset(int arr[], int n, int u,
    int unique[], int repeat[], int current_perm[],
    void (*callback)(int perm[], int n), int pos) {   // multiset generation
    if (pos == n) {                                   // permutation ready
        callback(current_perm, n);                    // output
        return;
    }

    for (int i = 0; i < u; i++) {                     // try each unique value
        if (repeat[i] != 0) {                         // still available
            current_perm[pos] = unique[i];            // place value
            repeat[i]--;                              // decrease count
            generate_multiset(arr, n, u, unique,
                repeat, current_perm, callback,
                pos + 1);                             // recurse
            repeat[i]++;                              // restore count
        }
    }
}

void multiset_permutations(int arr[], int n,
    void (*callback)(int perm[], int n)) {            // multiset wrapper
    if (n <= 0 || arr == NULL)                        // input check
        return;

    int* unique = (int*)malloc(n * sizeof(int));      // unique values
    int* repeat = (int*)malloc(n * sizeof(int));      // frequencies
    int* current_perm = (int*)malloc(n * sizeof(int));// current permutation
    int k = 0;
    int u = 0;
    sort(arr, n);                                     // sort input
    
    for (int i = 0; i < n; i++) {                     // count frequencies
        if (i + 1 != n && arr[i] == arr[i + 1])
            k++;
        else {
            k++;
            unique[u] = arr[i];                       // store value
            repeat[u] = k;                            // store count
            u++;
            k = 0;
        }
    }

    int c = num_unique_permutations(repeat, n, u);    // count permutations

    generate_multiset(arr, n, u, unique,
        repeat, current_perm, callback, 0);           // generate
    
    free(unique);                                     // free memory
    free(repeat);
    free(current_perm);
}

