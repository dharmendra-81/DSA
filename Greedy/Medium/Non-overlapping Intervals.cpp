// Time: O(nlogn) + O(n) 
class Solution {
    static bool comp(const vector<int> &a, const vector<int>& b){
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int lastEndTime = intervals[0][1];
        int cnt = 1;

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= lastEndTime){
                cnt++;
                lastEndTime = intervals[i][1];
            }
        }
        return intervals.size() - cnt;
    }
};