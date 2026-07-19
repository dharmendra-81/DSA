// Time: O(n) & Space: O(n)
class Solution {
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int> findPSEE(vector<int>& arr) {
        vector<int> pse(arr.size());
        stack<int> st;
        
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSEE(arr);
        const int MOD = 1e9 + 7;
        int total = 0;

        for(int i = 0; i < arr.size(); i++){
            int start = i - pse[i];
            int end = nse[i] - i;
            long long freq = 1LL * start * end; // Frequency of arr[i] being the minimum in subarrays
            int val = (freq * arr[i]) % MOD; // Contribution of arr[i] to the total sum
            total = (total + val) % MOD;
        }
        return total;
    }
};