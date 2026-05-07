#include<vector>
#include<map>
using namespace std;
class TakeuForward {
public:
    int getLongestSubarray(vector<int>& a, int k)  {
    map<int, int> preSumMap;
    int maxLen = 0;
    int sum = 0;
    for(int i=0; i<a.size(); i++) {
        sum += a[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        int rem = sum-k;
        if(preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    return maxLen;
  }
};