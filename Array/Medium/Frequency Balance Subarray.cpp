// Time Complexity: O(n^2) and Space Complexity: O(n)
class Solution {
    bool isBalanced(const unordered_map<int, int> &freq, const unordered_map<int, int> &freqCnt){
        if(freq.size() == 1) return true;
        if(freqCnt.size() != 2) return false;
        auto it = freqCnt.begin();
        int f1 = it->first;
        ++it;
        int f2 = it->first;
        int mini = min(f1, f2);
        int maxi = max(f1, f2);
        return maxi == 2*mini;
    }

public:
    int getLength(vector<int>& nums) {
        int ans = 1;
        for (int i = 0; i < nums.size(); i++){
            unordered_map<int, int> freq;
            unordered_map<int, int> freqCnt;
            for(int j = i; j < nums.size(); j++){
                int x = nums[j];

                if(freq[x] > 0){
                    freqCnt[freq[x]]--;
                    if(freqCnt[freq[x]] == 0) freqCnt.erase(freq[x]);
                }

                freq[x]++;
                freqCnt[freq[x]]++;
                if(isBalanced(freq, freqCnt)){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};