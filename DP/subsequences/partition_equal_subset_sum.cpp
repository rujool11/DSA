// Leetcode 416. Partition Equal Subset Sum

class Solution {
    public:
        int arraysum(vector<int>& nums) {
            int sum = 0;
            for (auto it: nums) sum += it;
            return sum;
        }
        
        int hasValidSum(int idx, vector<int>& nums, int target, vector<vector<int>>& dp) {
            if (target == 0) return dp[idx][target] = 1;
            if (idx == 0) return dp[idx][target] = (nums[0] == target) ? 1 : 0;
    
            if (dp[idx][target] != -1) return dp[idx][target];
    
            int nottake = hasValidSum(idx-1, nums, target, dp);
            int take = 0;
            if (target >= nums[idx]) take = hasValidSum(idx-1, nums, target-nums[idx], dp);
    
            return dp[idx][target] = take || nottake;
        }
    
        bool canPartition(vector<int>& nums) {
            // s1 = s2 = s/2
            // thus, false if arraysum(nums) is odd
            int s = arraysum(nums);
            if (s%2 != 0) return false;
            
            // if we find a subset with sum == arraysum(nums)/2, then other 
            // automatically s/2 => true
            int sum = s/2;
            vector<vector<int>> dp(nums.size(), vector<int>(sum+1, -1));
            return (bool) hasValidSum(nums.size()-1, nums, sum, dp);
        }
    };