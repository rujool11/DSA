// Leetcode 90. Subsets II

class Solution {
public:
    void doStuff(vector<vector<int>>& ans, vector<int>& helper, vector<int>& nums,int index){
        ans.push_back(helper); // since push subsets of all sizes
        for (int i=index; i<nums.size(); i++){
            if (i!=index && nums[i] == nums[i-1]) continue;

            helper.push_back(nums[i]);
            doStuff(ans, helper, nums, i+1);
            helper.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> helper;
        sort(nums.begin(), nums.end());
        doStuff(ans, helper, nums, 0);
        return ans;
    }
};