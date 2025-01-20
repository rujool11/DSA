//GFG Frog Jump
// Given an integer array height[] where height[i] represents the 
// height of the i-th stair, a frog starts from the first stair and wants 
// to reach the top. From any stair i, the frog has two options: it can 
// either jump to the (i+1)th stair or the (i+2)th stair. The cost of a
// jump is the absolute difference in height between the two stairs. 
// Determine the minimum total cost required for the frog to reach the top.

class Solution {
  public:
    
    int f(int ind, vector<int>& heights, vector<int>& dp) {
        
        if (ind == 0) return 0;
        if (dp[ind] != -1) return dp[ind];
        
        int a = f(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
        int b = INT_MAX;
        if (ind > 1)  b = f(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
        return dp[ind] = min(a, b);
    }
    
    
    int minCost(vector<int>& height) {
        
        int n = height.size();
        vector<int> dp(n + 1, -1);
        return f(n-1, height, dp);
    }
};
