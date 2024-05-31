// Leetcode 81. Search in rotated sorted array II
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // can have duplicate elements, can have multiple occurrences of target also
        int low = 0;
        int high = nums.size()-1;

        while (low <= high){
            int mid = low + (high - low)/2;

            if (nums[mid] == target) return true;

            else if (nums[mid] == nums[low] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

            else if (nums[low]<=nums[mid]){
                if (nums[low]<=target && target<=nums[mid]){
                    high = mid-1;
                }
                else { low = mid+1; }
            }

            else {
                if (nums[mid]<= target && target<= nums[high]){
                    low = mid +1;
                }
                else {high = mid - 1;}

            }

        }

        return false;
    }
};