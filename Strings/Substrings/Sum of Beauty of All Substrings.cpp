// O(n^2)
class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        //loop over all substr
        for(int i = 0; i < s.length(); i++){
            unordered_map<char, int> freq;
            for(int j = i; j < s.length(); j++){
                freq[s[j]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;

                //find max and min freq
                for(auto it: freq){
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }
                //add diff to sum
                sum += (maxi-mini);
            }
        }
        return sum;
    }
};

