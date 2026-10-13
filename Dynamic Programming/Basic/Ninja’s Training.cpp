// Memoization
class Solution {
    int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
        if(day == 0){
            int mx = 0;
            for(int task = 0; task <= 2; task++){
                if(task != last){
                    mx = max(mx, points[0][task]);
                }
            }
            return mx;
        }
        
        if(dp[day][last] != -1) return dp[day][last];
        
        int mx = 0;
        for(int task = 0; task <= 2; task++){
            if(task != last){
                int sum = points[day][task] + f(day-1, task, points, dp);
                mx = max(mx, sum);
            }
        }
        return dp[day][last] = mx;
    }
    
    public:
    int ninjaTraining(int n, vector<vector<int>> &points) {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(n-1, 3, points, dp);
    }
};

// Tabulation
class Solution {
    public:
    int ninjaTraining(int n, vector<vector<int>> &points) {
        vector<vector<int>> dp(n, vector<int>(4, 0));

        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]) );

        for(int day = 1; day < n; day++){
            for(int last = 0; last < 4; last++){
                dp[day][last] = 0;

                for(int task = 0; task <= 2; task++){
                    if(task != last){
                        int sum = points[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last], sum);
                    }
                }
            }
        }

        return dp[n-1][3];
    }
};

// Space Optimization
class Solution {
    public:
    int ninjaTraining(int n, vector<vector<int>> &points) {
        vector<int> prev(4, 0);

        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]) );

        for(int day = 1; day < n; day++){
            vector<int> temp(4, 0);
            for(int last = 0; last < 4; last++){
                temp[last] = 0;

                for(int task = 0; task <= 2; task++){
                    if(task != last){
                        int sum = points[day][task] + prev[task];
                        temp[last] = max(temp[last], sum);
                    }
                }
            }
            prev = temp;
        }

        return prev[3];
    }
};