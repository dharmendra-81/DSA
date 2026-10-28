class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        int mx = 1, last = 0;
        
        vector<int> dp(n, 1);
        vector<int> hash(n);
        vector<int> lis;
        
        for(int ind = 0; ind < n; ind++){
            hash[ind] = ind;
            for(int prev = 0; prev < ind; prev++){
                if(arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind]){
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }
            
            if(dp[ind] > mx){
                mx = dp[ind];
                last = ind;
            }
        }
        
        lis.push_back(arr[last]);
        while(hash[last] != last){
            last = hash[last];
            lis.push_back(arr[last]);
        }
        reverse(lis.begin(), lis.end());

        return lis;
    }
};