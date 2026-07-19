class prevSolution {
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

    vector<int> findNGE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] <= arr[i])
                st.pop();

            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nge;
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

    vector<int> findPGEE(vector<int>& arr) {
        vector<int> pge(arr.size());
        stack<int> st;
        
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] < arr[i])
                st.pop();

            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

public:
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSEE(arr);
        long long total = 0;

        for(int i = 0; i < arr.size(); i++){
            int start = i - pse[i];
            int end = nse[i] - i;
            long long val = 1LL * start * end * arr[i]; 
            total += val;
        }
        return total;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> nge = findNGE(arr);
        vector<int> pge = findPGEE(arr);
        long long total = 0;

        for(int i = 0; i < arr.size(); i++){
            int start = i - pge[i];
            int end = nge[i] - i;
            long long val = 1LL * start * end * arr[i]; 
            total += val;
        }
        return total;
    }
};

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        prevSolution obj;
        return obj.sumSubarrayMaxs(nums) - obj.sumSubarrayMins(nums);
    }
};
// Time: O(10n) & Space: O(10n)