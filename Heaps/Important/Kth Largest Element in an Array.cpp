//  Time: O(n log k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > minpq;

        for(int num: nums){
            minpq.push(num);
            if(minpq.size() > k) minpq.pop();
        }
        return minpq.top();
    }
};

//  Quick Select
class Solution {
    int partition(vector<int> &nums, int low, int high) {
            // Pick a random index between low and high
            int randIdx = low + rand() % (high - low + 1);
            swap(nums[randIdx], nums[high]); // Move random pivot to the end
            
            int pivot = nums[high];
            int i = low;

            for (int j = low; j < high; j++) {
                if (nums[j] <= pivot) {
                    swap(nums[i], nums[j]);
                    i++;
                }
            }

            swap(nums[i], nums[high]);
            return i;
    }

    int quickSelect(vector<int> &nums, int low, int high, int ind) {
        if(low == high) return nums[low];
        int p = partition(nums, low, high);
        if(p == ind) return nums[p];
        if(p < ind) return quickSelect(nums, p+1, high, ind);
        return quickSelect(nums, low, p-1, ind);
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int ind = nums.size() - k;
        return quickSelect(nums, 0, nums.size()-1, ind);
    }
};