// Time Complexity: O(nlogn) + O(n*m) 
class Solution{
    bool static comp(vector<int> &j1, vector<int> &j2){
        return j1[2] > j2[2];
    }

    public:
    vector<int> jobScheduling(vector<vector<int>> &jobs) {
        int n = jobs.size();
        sort(jobs.begin(), jobs.end(), comp);
        int maxDeadline = -1;
        for(auto &job: jobs){
            maxDeadline = max(maxDeadline, job[1]);
        }

        vector<int> slots(maxDeadline+1, -1);
        int cnt = 0, profit = 0;
        for(int i = 0; i < n; i++){
            for(int j = jobs[i][1]; j > 0; j--){
                if(slots[j] == -1){
                    cnt++;
                    slots[j] = jobs[i][0];
                    profit += jobs[i][2];
                    break;
                }
            }
        }
        return {cnt, profit};
    }
}