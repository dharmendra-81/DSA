// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/
class Solution {
public:
    long long countChildren(vector<int>& candies, int perChild) {
        long long children = 0;
        for (int x : candies) {
            children += x / perChild;
        }
        return children;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long children = countChildren(candies, mid);

            if (children >= k) { //Atleast k children
                ans = mid;        // valid answer
                low = mid + 1;    // try increasing candies
            } else {
                high = mid - 1;   // try decreasing
            }
        }

        return ans;
    }
};