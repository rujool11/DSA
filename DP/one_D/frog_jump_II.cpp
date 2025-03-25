//GFG Frog Jump
// Given an integer array height[] where height[i] represents the 
// height of the i-th stair, a frog starts from the first stair and wants 
// to reach the top. From any stair i, the frog has two options: it can 
// either jump to the (i+1)th stair or the (i+2)th stair. The cost of a
// jump is the absolute difference in height between the two stairs. 
// Determine the minimum total cost required for the frog to reach the top.

class Solution {
    public:
    
      int f(int n, vector<int>& height, vector<int>& dp) {
          if (n==0) return 0; // convert to 0 based indexing so 0 to n-1
          
          if (dp[n] != -1) return dp[n];
          int a = f(n-1, height, dp) + abs(height[n] - height[n-1]);
          int b = INT_MAX; // initialize as INT_MAX for the case when n > 1
          // if it could have come from n-2, i.e n >= 2, calculate for that
          if (n > 1) b = f(n-2, height, dp) + abs(height[n] - height[n-2]);
          return dp[n] = min(a, b);
      }
      
      int minCost(vector<int>& height) {
          int n = height.size();
          vector<int> dp(n+1, -1);
          return f(n-1, height, dp);
      }
  };

// space optimized ->

