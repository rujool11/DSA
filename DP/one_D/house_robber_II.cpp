// Leetcode 213. House robber II

class Solution {
public:
    int Rob(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        // call house robber 1 function for array without 0th and last element
        // handle edge case of 1 el only
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> temp1, temp2;
        for (int i=0; i<nums.size(); i++) {
            if (i!=0) temp1.push_back(nums[i]);
            if (i!=nums.size()-1) temp2.push_back(nums[i]);
        }

        return max(Rob(temp1), Rob(temp2));
    }
};