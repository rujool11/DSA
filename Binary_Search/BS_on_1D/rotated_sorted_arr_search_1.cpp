// Leetcode 33. Search in Rotated Sorted Array
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;

        int low = 0;
        int high = nums.size()-1;

        while (low<=high){
            int mid = low + (high-low)/2;

            if (nums[mid] == target) return mid;

            else if (nums[low] <= nums[mid]) // left half sorted
            {
                if (nums[low]<=target && target<=nums[mid]) // target in left half
                {
                    high = mid - 1;
                }

                else { low = mid + 1;}
            }

            else // right half sorted
            {
                if (nums[mid]<= target && target<=nums[high]) // target in right half
                {
                    low = mid + 1;
                }

                else {high = mid -1 ;}
            }
        }

        
        return -1;
    }
};