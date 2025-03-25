// Leetcode 198. house robber

// recursion ->
class Solution {
public:
    int f(int ind, vector<int>& nums) {

        if (ind == 0) return nums[0];
        if (ind<0) return 0;

        int pick = nums[ind] + f(ind-2, nums);
        int notpick = f(ind-1, nums);

        return max(pick, notpick);
    }
     
    int rob(vector<int>& nums) {
        // nax money such that no two adjacent houses are touched

        int n = nums.size();
        return f(n-1, nums);
    }
};

// --------------------------------------------------------------------------------------
// memoization ->

class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int>& dp) {

        if (ind == 0) return nums[0];
        if (ind<0) return 0;
        
        if (dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + f(ind-2, nums, dp);
        int notpick = 0 + f(ind-1, nums, dp); // 0 since we are not picking the current house;w


        return dp[ind] = max(pick, notpick);
    }
     
    int rob(vector<int>& nums) {
        // nax money such that no two adjacent houses are touched

        int n = nums.size();
        vector<int> dp(n+1, -1);
        return f(n-1, nums, dp);
    }
};

// -----------------------------------------------------------------------------------------
// tabulation ->

class Solution {
public:
    int f(int n, vector<int>& nums, vector<int>& dp) {

        dp[0] = nums[0];
        
        int take, nottake;

        for (int i=1; i<n; i++) {

            nottake = dp[i-1];
            take = nums[i];
            if (i > 1) take += dp[i-2];
            
            dp[i] = max(take, nottake);
        }

        return dp[n-1];
    }
     
    int rob(vector<int>& nums) {
        // nax money such that no two adjacent houses are touched

        int n = nums.size();
        vector<int> dp(n);
        return f(n, nums, dp);
    }
};

// ----------------------------------------------------------------------------------------------
// tabulation space optimized ->

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int take, nottake, curr;
        int before = nums[0];
        int two_before = 0;

        for (int i=0; i<n; i++) {

            nottake = before;
            take = nums[i];
            if (i > 1) take += two_before;

            curr = max(take, nottake);
            two_before = before;
            before = curr;
        }

        return curr;
    }
};

// -----------------------------------------------------------------------------------------
