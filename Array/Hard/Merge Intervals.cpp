//  56
//  Brute Force
// O(N*logN) + O(2N)
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); 
    //sort the given intervals:
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) { // select an interval:
        int start = arr[i][0];
        int end = arr[i][1];
        //Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }
        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// Better 
// O(N*logN) + O(N)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       int n = intervals.size(); 
       //sort the given intervals:
       sort(intervals.begin(), intervals.end());
       vector<vector<int>> ans;
       for (int i = 0; i < n; i++) {
        // if the current interval does not lie in the last interval:
        if (ans.empty() || intervals[i][0] > ans.back()[1]) {
            ans.push_back(intervals[i]);
        }
        // if the current interval lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
    }
};