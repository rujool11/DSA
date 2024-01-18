class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> ans;
        for (int i=0;i<nums.size();i++){
            if (hash.find(target-nums[i])!=hash.end()){
                ans.push_back(i);
                ans.push_back(hash[target-nums[i]]);
            }

            hash[nums[i]] = i;
        }
        
        return ans;
    }
};
