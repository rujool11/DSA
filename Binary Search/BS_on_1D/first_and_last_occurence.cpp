// Leetcode 34. First and last position of element in sorted array
// to count number of occurrences in a sorted array, do last_occ - first_occ + 1
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(-1); //starting
        res.push_back(-1); //ending

        if (nums.size()==0) { return {-1,-1}; }

        int low = 0;
        int high = nums.size()-1;
        
        while (low<=high){
            int mid = low + (high-low)/2;

            if (nums[mid] == target){
                res[0] = mid;
                high = mid - 1;
            }
            else if (nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        low = 0;
        high = nums.size()-1;

        while (low<=high){
            int mid = low + (high-low)/2;

            if (nums[mid] == target){
                res[1] = mid;
                low = mid + 1;
            }
            else if (nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};

