// Time: O(2n + nlogn) , Space: O(n)
class Solution {
    static bool comp(const tuple<int, int, int> &t1, const tuple<int, int, int>& t2){
        if (get<1>(t1) == get<1>(t2)) {
            return get<2>(t1) < get<2>(t2); // Prefer smaller index if finish times are equal
        }
        return get<1>(t1) < get<1>(t2);
    }
    
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n = s.size();
        vector<tuple<int, int, int>> arr(n);
        vector<int> ds;
        
        for(int i = 0; i < n; i++){
            arr[i] = {s[i], f[i], i+1};
        }
        
        sort(arr.begin(), arr.end(), comp);       
        int freeTime = -1;
        
        for(int i = 0; i < n; i++){
            if(get<0>(arr[i]) > freeTime){
                freeTime = get<1>(arr[i]);
                ds.push_back(get<2>(arr[i]));
            }
        }
        
        sort(ds.begin(), ds.end());
        return ds;
    }
};
