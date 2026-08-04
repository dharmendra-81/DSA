//  Time: O(nlogn) & Space: O(n)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> mp;
        int rank = 1;

        for(int num: sorted){
            if(mp.find(num) == mp.end()){
                mp[num] = rank++;
            }
        }

        vector<int> ans;
        for(int num: arr){
            ans.push_back(mp[num]);
        }
        return ans;
    }
};