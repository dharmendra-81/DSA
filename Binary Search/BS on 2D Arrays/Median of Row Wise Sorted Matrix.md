Given a row-wise sorted matrix of size M*N, where M is no. of rows and N is no. of columns, find the median in the given matrix.  
Note: M*N is odd.

---
# Brute-Force
```cpp
int findMedian(vector<vector<int>>& matrix) {
        // Create a list to store all elements
        vector<int> elements;
        // Traverse each row of the matrix
        for (auto& row : matrix) {
            for (int val : row) {
                elements.push_back(val);
            }
        }
        // Sort the collected elements
        sort(elements.begin(), elements.end());
        // Return the middle element (median)
        int n = elements.size();
        return elements[n / 2];
    }
    O( M X N log(M N) )
```

# Optimal
```cpp
class Solution {
public:
    // Function to count elements less than or equal to mid in a row
    int countLessEqual(vector<int>& row, int mid) {
        // Using upper_bound to find count efficiently
        return upper_bound(row.begin(), row.end(), mid) - row.begin();
    }

    int findMedian(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Minimum possible element in matrix
        int low = matrix[0][0];
        // Maximum possible element in matrix
        int high = matrix[0][cols - 1];

        for (int i = 1; i < rows; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][cols - 1]);
        }

        // Binary search over the value range
        while (low < high) {
            int mid = (low + high) / 2;
            // Count elements ≤ mid
            int count = 0;
            for (int i = 0; i < rows; i++) {
                count += countLessEqual(matrix[i], mid);
            }

            // If count is less than half, median is greater
            if (count < (rows * cols + 1) / 2)
                low = mid + 1;
            else
                high = mid;
        }
        // Final low is the median
        return low;
    }
};
O(rows × log(max - min) × log(cols))
```
