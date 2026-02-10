void swap(int* a, int* b) {                           // swap two values
    int n1 = *a;
    *a = *b;
    *b = n1;
}

void sort(int arr[], int n) {                         // simple bubble sort
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void generate_lexicographic(int arr[], int n,
    void (*callback)(int perm[], int n), int pos) {   // lexicographic generation
    if (pos == n) {                                   // permutation ready
        callback(arr, n);                             // output
        return;
    }

    for (int i = pos; i < n; i++)                     // sort suffix
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[i])
                swap(&arr[i], &arr[j]);

    for (int i = pos; i < n; i++) {                   // fix current position
        swap(&arr[pos], &arr[i]);                     // place smallest
        generate_lexicographic(arr, n,
            callback, pos + 1);                       // recurse
        swap(&arr[i], &arr[pos]);                     // restore order

        for (int j = i; j < n - 1; j++)               // keep suffix sorted
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
    }
}

void permutations_recursive_lexicographic(int arr[], int n,
    void (*callback)(int perm[], int n)) {            // lexicographic wrapper
    if (n <= 0 || arr == NULL)                        // input check
        return;

    sort(arr, n);                                     // initial sort
    
    generate_lexicographic(arr, n, callback, 0);      // start recursion
}