// Leetcode 153. Mininum in rotated sorted array
class Solution {
public:
    int findMin(vector<int>& nums) {
       int low = 0;
       int high = nums.size()-1;
       int res = INT_MAX;

       while (low<=high){
           int mid = low + (high-low)/2;

           if (nums[low]<=nums[high]) // already sorted
           {
               res = min(nums[low], res);
               break;
           }

           if (nums[low] <= nums[mid]) // left half sorted
           {
               res = min(nums[low], res);
               low = mid+1; // eliminate left half
           }

           else { // right half sorted
               res = min(nums[mid], res);
               high = mid - 1; // eliminate right half
           }
       } 

       return res;
    }
};