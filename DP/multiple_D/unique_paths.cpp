// Leetcode 62. Unique Paths

// memoization
class Solution {
public:
    int f(int x, int y, int m, int n, vector<vector<int>>& dp) {
        // Reached destination
        if (x == m-1 && y == n-1) return 1;

        // OOB check
        if (x >= m || y >= n) return 0;
        if (dp[x][y] != -1) return dp[x][y];
        return dp[x.][y] = f(x+1, y, m, n, dp) + f(x, y+1, m, n, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, m, n, dp);
    }
};

// tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[m-1][n-1] = 1;  // base case

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i+1 < m) dp[i][j] += dp[i+1][j];   // down
                if (j+1 < n) dp[i][j] += dp[i][j+1];   // right
            }
        }

        return dp[0][0];
    }
};
