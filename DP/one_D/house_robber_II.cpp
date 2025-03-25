// Leetcode 213. House robber II

class Solution
{
public:
    int f(int n, vector<int> &nums, vector<int> &dp)
    {
        dp[0] = nums[0];

        int take, nottake;
        for (int i = 1; i < n; i++)
        {
            take = dp[i - 1];
            nottake = nums[i];
            if (i > 1)
                nottake += dp[i - 2];

            dp[i] = max(take, nottake);
        }

        return dp[n - 1];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0]; // edge case of only 1 el

        // first and last element both cannot come together
        // so, call f for array without first and last, and get max of those
        vector<int> nums_1, nums_2;
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                nums_1.push_back(nums[i]);
            if (i != n - 1)
                nums_2.push_back(nums[i]);
        }
        vector<int> dp_1(n);
        vector<int> dp_2(n);

        return max(f(n - 1, nums_1, dp_1), f(n - 1, nums_2, dp_2));
    }
};