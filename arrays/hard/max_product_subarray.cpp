// Leetcode 153. Max Product Subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int prefix = 1;
       int suffix = 1;
       int res = INT_MIN;

       for (int i=0;i<nums.size();i++){
        // to break when encountering 0, check notes
           if (prefix == 0) { prefix = 1; }
           if (suffix == 0) { suffix = 1; }

           prefix *= nums[i];
           suffix *= nums[nums.size()-1-i];
           res = max(res, max(prefix, suffix));
       }

       return res;
    }
};