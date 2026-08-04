//  Time: O(nlogk) where n is the number of tasks and k is the number of unique tasks
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        priority_queue<int> pq;
        int time = 0;

        for(char task: tasks){
            mp[task]++;
        }

        for(auto it: mp){
            pq.push(it.second);
        }

        while(!pq.empty()){
            vector<int> remaining;
            int slots = n + 1; // every round have n+1 slots
            int tasksDone = 0;
            while(slots>0 && !pq.empty()){
                int cnt = pq.top();
                pq.pop();
                cnt--;
                tasksDone++;
                if(cnt > 0) remaining.push_back(cnt);
                slots--;
            }

            for(int cnt: remaining) pq.push(cnt);
            if(pq.empty()) time += tasksDone;
            else time += n + 1;
        }
        return time;
    }
};