// Leetcode 931. minimum falling path sum

// memoization -->
class Solution {
    public:
        int f(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix, int n) {
            if (j<0 || j>=n) return 1e9; // to avoid overflow do not use INT_MAX here
            if (i == 0) return  dp[i][j] = matrix[i][j];
            if (dp[i][j] != -1e9) return dp[i][j]; // using -1 here causes TLE
            // since value can also be computed to be -1 in some cases, 
            // and can thus add unncessary calls

            int leftdiag = matrix[i][j] + f(i-1, j-1, dp, matrix, n);
            int top = matrix[i][j] + f(i-1, j, dp, matrix, n);
            int rightdiag = matrix[i][j] + f(i-1, j+1, dp, matrix, n);
    
            return dp[i][j] = min({leftdiag, top, rightdiag});
        }
    
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
            vector<vector<int>> dp(n, vector<int>(n, -1e9));
            int ans = INT_MAX;
            for (int j=0; j<n; j++) { 
                // try all in last row since variable start and end positions
                ans = min(ans, f(n-1, j, dp, matrix, n));
    
            }
            return ans;
        }
    };

// tabulation -->
class Solution {
    public:
        int f(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix, int n) {
            if (j<0 || j>=n) return 1e9; // to avoid overflow do not use INT_MAX here
            if (i == 0) return  dp[i][j] = matrix[i][j];
            if (dp[i][j] != -1e9) return dp[i][j]; // using -1 here causes TLE
            // since it can also be computed to be -1 in some cases
    
            int leftdiag = matrix[i][j] + f(i-1, j-1, dp, matrix, n);
            int top = matrix[i][j] + f(i-1, j, dp, matrix, n);
            int rightdiag = matrix[i][j] + f(i-1, j+1, dp, matrix, n);
    
            return dp[i][j] = min({leftdiag, top, rightdiag});
        }
    
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
            vector<vector<int>> dp(n, vector<int>(n, -1e9));
    
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (i == 0) {
                        dp[i][j] = matrix[i][j]; 
                        continue;
                    }
    
                    int leftdiag = 1e9;
                    int top = 1e9;
                    int rightdiag = 1e9;
    
                    if (j-1 >= 0) leftdiag = matrix[i][j] + dp[i-1][j-1];
                    top = matrix[i][j] + dp[i-1][j];
                    if (j+1 < n) rightdiag = matrix[i][j] + dp[i-1][j+1];
    
                    dp[i][j] = min({leftdiag, top, rightdiag});
                }
            }
    
            int ans = INT_MAX;
            for (int j=0; j<n; j++) { 
                // try all in last row since variable start and end positions
                ans = min(ans, dp[n-1][j]);
    
            }
            return ans;
        }
    };