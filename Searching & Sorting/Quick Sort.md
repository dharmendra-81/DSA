- Average case : O(n logn )
- Worst Case : O( $N^2$ )
- Not stable
```cpp
int partition(vector<int> &nums, int low, int high) {
    int pivot = nums[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            swap(nums[i], nums[j]);
            i++;
        }
    }

    swap(nums[i], nums[high]);
    return i;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

```
