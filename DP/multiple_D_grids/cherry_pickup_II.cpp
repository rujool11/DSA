//Leetcode 1463. cherry pickup II

class Solution {
    public:
        long long f(int i, int j1, int j2, vector<vector<int>>& grid, 
                    vector<vector<vector<long long>>>& dp, int r, int m) {
            // Check if indices are within bounds
            // IMP: i used only once since we are moving downwards for both
            if (i < 0 || i >= r || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
                return -1e12;
    
            if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
    
            // Base case: Last row
            if (i == r - 1) {
                if (j1 == j2)
                    return dp[i][j1][j2] = grid[i][j1];
                else
                    return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
            }
    
            long long maxi = -1e12;
            // Explore all moves for both travelers simultaneously
            for (int dj1 = -1; dj1 <= 1; dj1++) {
                for (int dj2 = -1; dj2 <= 1; dj2++) {
                    long long val = 0;
                    // Collect cherries for current cell(s)
                    if (j1 == j2)
                        val = grid[i][j1];
                    else
                        val = grid[i][j1] + grid[i][j2];
    
                    // Add result of the recursive call
                    val += f(i + 1, j1 + dj1, j2 + dj2, grid, dp, r, m);
                    maxi = max(maxi, val);
                }
            }
            return dp[i][j1][j2] = maxi;
        }
    
        int cherryPickup(vector<vector<int>>& grid) {
            int r = grid.size();
            int m = grid[0].size();
            // dp dimensions: row x column x column
            vector<vector<vector<long long>>> dp(r, 
                vector<vector<long long>>(m, vector<long long>(m, -1)));
            return (int)f(0, 0, m - 1, grid, dp, r, m);
        }
    };
