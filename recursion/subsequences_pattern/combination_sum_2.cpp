class Solution {
public:
    // IMP -> cannot have duplicates
    // eg. [1,7,1,2] target : 8; so [1,7] and [7,1] both cannot be present 
    void doStuff(vector<vector<int>>& ans, vector<int>& helper, vector<int> candidates, int target, int index){
            // dont have to check (index==candidates.size()) because of base case in recursion tree (look in nb) 
            if (target==0){
                ans.push_back(helper);
                return;
            }
            

        for (int i=index; i<candidates.size();i++){
            if (i>index && candidates[i] == candidates[i-1]) continue; // to avoid duplicates
            if (candidates[i] > target) break; // since sorted

            helper.push_back(candidates[i]);
            doStuff(ans, helper, candidates, target-candidates[i], i+1);
            helper.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> helper;
        doStuff(ans, helper, candidates, target, 0);
        return ans;
    }
};