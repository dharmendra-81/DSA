
- **Change the array `nums` such that the first `k` elements of `nums` contain the unique elements in the order they were present in `nums` initially. The remaining elements of `nums` are not important as well as the size of `nums`.**
- **Return `k`.**


# Brute Force Approach
```cpp
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
```

# Optimal Solution
```cpp
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
```

