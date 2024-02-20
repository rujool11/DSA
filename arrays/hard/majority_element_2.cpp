class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;

        vector<int> res;

        for (auto num: nums){
            hash[num]++;
        }


        for (auto it: hash){
            if (it.second>nums.size()/3){
                res.push_back(it.first);
            }
        }
        // look up Boyer Moore majority vote algorithm  solution
        return res;

    }
};
