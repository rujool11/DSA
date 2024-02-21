// Leetcode 18. 4Sum
// Leetcode 18. 4Sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
    
        // fix i and j and use k and l as 2 pointers

        for (int i=0;i<nums.size()-3;i++){
            if (i>0 && nums[i]==nums[i-1]){continue;}

            for (int j=i+1;j<nums.size()-2;j++){
                if (j>(i+1) && nums[j]==nums[j-1]){continue;}

                int k = j+1;
                int l = nums.size()-1;

                while (k<l){
                    long long sum = nums[i]+nums[j]+nums[k]+nums[l];
                    if (sum==target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        res.push_back(temp);
                        l--;
                        k++;
                        while (k<l && nums[k]==nums[k-1]){k++;}
                        while (k<l && nums[l]==nums[l+1]){l--;}
                    }
                    else if (sum<target){k++;}
                    else{l--;}
                }
            }
        }

        return res;
    }
};// code seems to be correct, problems submitting on leetcode, runtime error, check once