class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        for (auto num: nums){
            hash[num]++;
        }


        for (auto it: hash){
            if (it.second>nums.size()/2){return it.first;}
        }

        return -1;
    }
};
