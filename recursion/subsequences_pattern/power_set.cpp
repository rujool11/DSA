// Leetcode 78. Subsets
// all possible subsequences/ subsets  (power set)

class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& helper, vector<int>& nums, int index){
        if (index == nums.size()){
            ans.push_back(helper);
            return;
        }

        //include nums[index] in subset
        helper.push_back(nums[index]);
        solve(ans, helper, nums, index+1);

        // exclude nums[index] --> backtrack
        helper.pop_back(); // need to remove last included element (backtrack)
        solve(ans, helper, nums, index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        // at each step, decide whether to include current element or not
        // branchign -> one including, one excluding

        //base case -> curr index = size of i/p
        vector<int> helper;
        solve(ans, helper, nums, 0);
        return ans;
    }
};