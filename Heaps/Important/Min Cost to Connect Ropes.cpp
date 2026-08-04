//  Time: O(nlogn) & Space: O(n)
class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int> > pq;
        int cost = 0; 
        
        for(int num: arr){
            pq.push(num);
        }
        
        while(pq.size() >= 2){
            int min1 = pq.top();
            pq.pop();
            int min2 = pq.top();
            pq.pop();
            pq.push(min1 + min2);
            cost += min1 + min2;
        }
        return cost;
    }
};