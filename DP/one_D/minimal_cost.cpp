// GFG minimal cost 
// same as frog_jump_II, but can go from i+1 to i+k jumps

class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX); // dp[i] will store the minimum cost to reach stone i.
        
        dp[0] = 0; // Base case: cost to reach the first stone is 0.

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k && i - j >= 0; j++) {
                dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
            }
        }
        
        return dp[n - 1]; // The minimum cost to reach the last stone.
    }
};
