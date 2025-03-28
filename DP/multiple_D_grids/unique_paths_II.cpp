// Leetcode 63. Unique Paths II

class Solution {
    public:
        int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
            if (i<0 || j<0) return 0; // OOB
            if (grid[i][j] == 1) return dp[i][j] = 0; // no path from there
            // if current cell is obstacle
            if (i==0 && j==0) return 1; // start
            
            if (dp[i][j] != -1) return dp[i][j];
    
            int up = 0;
            int left = 0;
    
            up = f(i-1, j, grid, dp);
            left = f(i, j-1, grid, dp);
    
            return dp[i][j] = left + up;
        }
    
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
    
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return f(m-1, n-1, obstacleGrid, dp);
        }
    };

// tabulation -->
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
    
            if (obstacleGrid[0][0] == 1) return 0; // If start is blocked, no paths
    
            vector<vector<int>> dp(m, vector<int>(n, 0));
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (obstacleGrid[i][j] == 1) {
                        dp[i][j] = 0; // No path if there's an obstacle
                        continue;
                    }
    
                    if (i == 0 && j == 0) {
                        dp[i][j] = 1; // Start position
                        continue;
                    }
    
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
    
                    dp[i][j] = up + left;
                }
            }
    
            return dp[m - 1][n - 1];
        }
    };
    