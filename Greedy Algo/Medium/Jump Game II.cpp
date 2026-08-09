// Time: O(n^n) 
class Solution {
    int f(int ind, int jumps, vector<int>& arr){
        int mini = INT_MAX;
        if(ind >= arr.size()-1) return jumps;
        for(int i = 1; i <= arr[ind]; i++){
            mini = min(mini, f(ind+i, jumps+1, arr));
        }
        return mini;
    }

public:
    int jump(vector<int>& nums) {
        return f(0, 0, nums);
    }
};