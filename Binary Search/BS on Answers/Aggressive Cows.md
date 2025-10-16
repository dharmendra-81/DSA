You are given an array **'arr'** of size **'n'** which denotes the position of stalls.  
You are also given an integer **'k'** which denotes the number of aggressive cows.  
You are given the task of assigning stalls to **'k'** cows such that the minimum distance between any two of them is the maximum possible.  
Find the maximum possible minimum distance.

---
```cpp
class Solution {
public:
    bool canWePlace(vector<int> &stalls, int dist, int cows){
        int cntCows = 1;
        int lastPos = stalls[0];
        for(int i = 1; i < stalls.size(); i++){
            if(stalls[i] - lastPos >= dist){
                cntCows++;
                lastPos = stalls[i];
            }
            if(cntCows >= cows)
                return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k){
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls.back() - stalls.front();
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canWePlace(stalls, mid, k)){
                ans = mid;       // possible to place cows at distance mid
                low = mid + 1;   // try for bigger distance
            } else {
                high = mid - 1;  // try for smaller distance
            }
        }

        return ans;
    }
};

```