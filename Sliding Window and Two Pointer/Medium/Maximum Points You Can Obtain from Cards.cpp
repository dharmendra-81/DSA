class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, maxPoints = 0;

        for(int i = 0; i < k; i++){
            sum += cardPoints[i];
        }
        maxPoints = sum;

        int right = cardPoints.size() - 1;
        for(int i = k-1; i >= 0; i--){
            sum += cardPoints[right] - cardPoints[i];
            right--;
            maxPoints = max(maxPoints, sum);
        }
        return maxPoints;
    }
};

// Time: O(2k)