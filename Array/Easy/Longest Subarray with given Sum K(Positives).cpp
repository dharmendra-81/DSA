#include<vector>
using namespace std;
class TakeuForward {
public:
    int getLongestSubarray(vector<int>& a, long long k)  {
       int left=0, right=0;
       long long sum = a[0];
       int maxLen=0;
       while(right < a.size()) {
        while(sum > k && left<= right){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            maxLen=max(maxLen, right-left+1);
        }
        right++;
        if(right < a.size() ){
            sum += a[right];
        }
    }
    return maxLen;
    }
};