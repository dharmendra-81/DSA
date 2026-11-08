class Solution {
  public:
    int solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        long long currentTime = 0;
        long long totalWait = 0;
        
        for(int burst: bt){
            totalWait += currentTime;
            currentTime += burst;
        }
        return totalWait/bt.size();
    }
};