You have been given a non-empty grid **‘mat’** with **'n'** rows and **'m'** columns consisting of only 0s and 1s. All the rows are sorted in ascending order.  
Your task is to find the index of the row with the maximum number of ones.  
**Note:** If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1.

---
# Brute Force
```cpp
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;
    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        int cnt_ones = 0;
        for (int j = 0; j < m; j++) {
            cnt_ones += matrix[i][j];
        }
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}
O(n X m)
```



