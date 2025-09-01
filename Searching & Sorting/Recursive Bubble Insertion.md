# Bubble Sort
```cpp
void bubble_sort(int arr[], int n) {
    if (n == 1) return;
    for (int j = 0; j < n - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            swap( arr[j], arr[j + 1] );
        }
    }
    bubble_sort(arr, n - 1);
}
```

# Insertion Sort
```cpp
void insertion_sort(int arr[], int i, int n) {
    if (i == n) return;
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        swap(arr[j], arr[j - 1]);
        j--;
    }
    insertion_sort(arr, i + 1, n);
}
```