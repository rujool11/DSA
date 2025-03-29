// Leetcode 120. triangle
// fixed starting point, variable ending point

// memoization ->
class Solution {
    public:
        int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp, int n) {
            if (i == n-1) return dp[i][j] = triangle[i][j];
            if (dp[i][j] != -1) return dp[i][j];
    
            int down = triangle[i][j] + f(i+1, j, triangle, dp, n);
            int diagonal = triangle[i][j] + f(i+1, j+1, triangle, dp, n);
    
            return dp[i][j] = min(down, diagonal); 
        }
    
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            vector<vector<int>>dp (n, vector<int>(n, -1));
            return f(0, 0, triangle, dp, n);
        }
    };

// tabulation -->

class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            vector<vector<int>>dp (n, vector<int>(n, -1));
            
            for (int i=n-1; i>=0; i--) {
                for (int j=i; j>=0; j--) {
                    if (i == n-1) {
                        dp[i][j] = triangle[i][j];
                        continue;
                    }
    
                    int down = triangle[i][j] +  dp[i+1][j];
                    int diagonal = triangle[i][j] + dp[i+1][j+1];
    
                    dp[i][j] = min(down, diagonal);
                }
            }
    
            return dp[0][0];
        }
    };