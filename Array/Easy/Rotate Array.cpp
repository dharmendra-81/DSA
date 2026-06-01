#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n) and Space Complexity: O(k)
void rotateRight(int arr[], int n, int k) {
        if (n == 0) return;
        // Normalize k if greater than n
        k = k % n;
        // Store last k elements in a temporary array
        int temp[k];
        for (int i = n - k; i < n; i++) {
            temp[i - n + k] = arr[i];
        }
        // Shift the first n-k elements to the right by k steps
        for (int i = n - k - 1; i >= 0; i--) {
            arr[i + k] = arr[i];
        }
          // Copy back the k elements to the start
        for (int i = 0; i < k; i++) {
            arr[i] = temp[i];
        }
    }

// Time Complexity: O(n) and Space Complexity: O(1)
class Solution {
    public:
    void rotate(vector<int>& nums, int k) {
        k=k%(nums.size());
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
