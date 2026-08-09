// Time: O(nlogn) + O(2n) = O(nlogn)
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<double, int>> items;
        
        // calculate ratio(value / weight) 
        for(int i = 0; i < val.size(); i++){
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, i});
        }
        
        sort(items.begin(), items.end(), greater<pair<double, int>>());
        double ans = 0.0;
        
        for(auto [ratio, i]: items){
            if(capacity >= wt[i]){
                ans += val[i];
                capacity -= wt[i];
            }
            else{
                ans += ratio * capacity; //rem_wt / wt * val
                break;
            }
        }
        return ans;
    }
};
