// Leetcode 39. combination sum
class Solution {
public:

    void doStuff(set<vector<int>>& ans, vector<int>& helper,vector<int> candidates, int target, int index){
        if (index==candidates.size()){
            if (target == 0) ans.insert(helper);
            return;
        }

        // instead of having a variable_sum variable, we update target
        // as target - candidates[index] when included, and nothing when not
        // thus, target is dynamic and changes for every case

       if (candidates[index] <= target){
            helper.push_back(candidates[index]);
            // index same since we can have multiple of same value
            doStuff(ans, helper, candidates, target - candidates[index], index);
            helper.pop_back(); // backtrack
       }

       doStuff(ans, helper, candidates, target, index+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> helper;
        set<vector<int>> ans;
        doStuff(ans, helper, candidates, target, 0);
        vector<vector<int>> res(ans.begin(), ans.end());

        return res;
    }
};