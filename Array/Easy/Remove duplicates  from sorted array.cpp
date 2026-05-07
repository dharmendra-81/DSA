#include<vector>
#include<set>
using namespace std;    

//Brute Force Approach
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            set<int> set;
            for(int i=0;i<nums.size();i++){
                set.insert(nums[i]);
            }
            nums.clear();
            for(auto it=set.begin();it!=set.end();it++){
                nums.push_back(*it);
            }
            int k=set.size();
            set.clear();
            return k;
        }
    };

//Optimal Solution
int removeDuplicates(vector<int>& nums) {
            int i=0;
            for (int j=1;j<nums.size();j++){
                if(nums[i]!=nums[j]){
                    i++;
                    nums[i]=nums[j];
                }
            }
            return i+1;
        }

