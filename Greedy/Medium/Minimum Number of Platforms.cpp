// Time: O(2n + 2nlogn)
class Solution {
  public:
    int calculateMinPatforms(int at[], int dt[], int n) {
        sort(at, at + n);
        sort(dt, dt + n);

        int i = 0, j = 0;
        int platform = 0, ans = 0;
        while(i < n){
            if(at[i] <= dt[j]){
                platform++;
                i++;
            }
            else{
                platform--;
                j++;
            }
            ans = max(ans, platform);
        } 
        return ans;
    }
};