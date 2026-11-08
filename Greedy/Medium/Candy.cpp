// Using one array => Time: O(3n) & Space: O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);

        // Forward pass
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Backward pass
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int total = 0;
        for (int i = 0; i < candies.size(); i++) {
            total += candies[i];
        }
        return total;
    }
};

// Using Concept of Slope => Time: O(n) & Space: O(1)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1, i = 1;
        int n = ratings.size();

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum++;
                i++;
                continue;
            }

            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }

            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]){
                sum += down;
                i++;
                down++;
            }
            if(down > peak) sum += down-peak;
        }
        return sum;
    }
};

