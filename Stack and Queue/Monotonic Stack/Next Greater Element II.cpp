// Brute Force: O(n^2) 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < i+n; j++){
                int ind = j % n;
                if(nums[ind] > nums[i]){
                    nge[i] = nums[ind];
                    break;
                } 
            }
        }
        return nge;
    }
};

// Optimized: O(4n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = 2*n-1; i >= 0; i--){
            int ind = i % n;
            while(!st.empty() && st.top() <= nums[ind]){
                st.pop();
            }

            if(i < n){
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[ind]);
        }
        return nge;
    }
};