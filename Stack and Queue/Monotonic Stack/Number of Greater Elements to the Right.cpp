class Solution {
    vector<pair<int, int>> arr;   // {value, original index}
    vector<int> ans;

    void mergeSort(int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }

    void merge(int left, int mid, int right) {
        vector<pair<int, int>> temp;

        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {

            if (arr[i].first < arr[j].first) {
                ans[arr[i].second] += (right - j + 1);
                temp.push_back(arr[j++]);
            } else {
                temp.push_back(arr[i++]);
            }
        }

        while (i <= mid)
            temp.push_back(arr[i++]);

        while (j <= right)
            temp.push_back(arr[j++]);

        for (int k = left; k <= right; k++)
            arr[k] = temp[k - left];
    }

public:
    vector<int> countGreater(vector<int>& nums) {
        int n = nums.size();

        arr.resize(n); // resize the arr vector to hold pairs of (value, original index)
        ans.assign(n, 0); // initialize the ans vector with zeros

        for (int i = 0; i < n; i++)
            arr[i] = {nums[i], i};

        mergeSort(0, n - 1);

        return ans;
    }
};