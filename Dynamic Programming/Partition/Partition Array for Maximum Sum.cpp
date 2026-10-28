// Memoization
class Solution {
    int f(int i, int k, vector<int>& arr, vector<int> &dp){
        int n = arr.size();
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int maxSum = 0;
        int len = 0, maxEle = INT_MIN;
        for(int j = i; j < min(n, i+k); j++){
            len++;
            maxEle = max(maxEle, arr[j]);
            int sum = len * maxEle + f(j+1, k, arr, dp);
            maxSum = max(maxSum, sum);
        }
        return dp[i] = maxSum;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);

        return f(0, k, arr, dp);
    }
};

// Tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int i = n-1; i >= 0; i--){
            int maxSum = 0;
            int len = 0, maxEle = INT_MIN;

            for(int j = i; j < min(n, i+k); j++){
                len++;
                maxEle = max(maxEle, arr[j]);
                int sum = len * maxEle + dp[j+1];
                maxSum = max(maxSum, sum);
            }
            dp[i] = maxSum;
        }

        return dp[0];
    }
};