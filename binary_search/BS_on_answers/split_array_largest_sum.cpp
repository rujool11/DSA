// Leetcode 410. Split array largest sum
// exactly similar to painter's partition problem and book allocation problem

class Solution {
public:

    int countArrays(vector<int>& nums, int mid){
        int arrs = 1;
        int count = 0;
        for (int i=0;i<nums.size();i++){
            if (count+nums[i] <= mid) count += nums[i];
            else{
                arrs++;
                count = nums[i];
            }
        }

        return arrs;
    }

    int splitArray(vector<int>& nums, int k) {
        // same as book alocation problem, where k is the number of students. 
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int res = -1;

        while (low<=high){
            int mid = (high + low)/2;

            int arrays = countArrays(nums, mid);
            if (arrays <= k){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return res;
    }
};