class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        const int MOD = 1000;
        
        if (start == end) return 0;
        
        queue<pair<int, int>> q;
        q.push({start, 0});
        
        vector<int> dist(MOD, INT_MAX);
        dist[start] = 0;
        
        while(!q.empty()){
            auto [node, steps] = q.front();
            q.pop();
            
            for(auto it: arr){
                int num = (it * node) % MOD;
                
                if(steps + 1 < dist[num]){
                    dist[num] = steps + 1;
                    if(num == end) return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};