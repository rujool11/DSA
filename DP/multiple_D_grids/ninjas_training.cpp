// GFG geeks training
// Geek is going for a training program for n days. He can perform any of these activities: 
// Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek
// wants to improve all his skills, he can't do the same activity on two consecutive days. 
// Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the 
// merit points for Running, Fighting, and Learning on the i-th day, determine the maximum 
// total merit points Geek can achieve .

// memoization ->
class Solution {
  public:
    int f(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if (day == 0) {
            int maxi = 0;
            for (int i=0; i<3; i++) {
                if (i != last) maxi = max(maxi, arr[0][i]); // arr[0] since 0th day
            }
            return maxi;
        }
        
        if (dp[day][last] != -1) return dp[day][last];
        
        int maxi = 0;
        for (int task = 0; task<3; task++) {
            if (task != last) {
                int pts = arr[day][task] + f(day-1, task, arr, dp);
                maxi = max(maxi, pts);
            }    
        }
        
        return dp[day][last] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(4, -1));
        return f(arr.size()-1, 3, arr, dp);
    }
};

// tabulation -->

class Solution {
public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        // dp[i][j] denotes the maximum points up to day i, if the last task done was j (0,1,2) 
        // and j=3 indicates that no task was done the previous day.
        vector<vector<int>> dp(n, vector<int>(4, 0));
            
        // Base case for day 0:
        dp[0][0] = max(arr[0][1], arr[0][2]);            
        dp[0][1] = max(arr[0][0], arr[0][2]);            
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]}); 
            
        // Fill dp table for the remaining days
        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
                int maxi = 0;
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        int point = arr[day][task] + dp[day-1][task];
                        maxi = max(maxi, point);
                    }
                }
                dp[day][last] = maxi;
            }
        }
            
        return dp[n - 1][3];
    }
};