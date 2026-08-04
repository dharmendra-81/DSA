class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ind = 0;

        for(int i = 0; i < arr.size(); i++){
            pq.push(arr[i]);
            if(pq.size() > k){
                int top = pq.top();
                pq.pop();
                arr[ind++] = top;
            }
        }
        
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            arr[ind++] = top;
        }
    }
};