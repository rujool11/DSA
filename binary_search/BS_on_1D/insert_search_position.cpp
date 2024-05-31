// leetcode 35. search insert position
// basically to find out lower bound 

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // basically find the lower bound: arr[ind] >= target
        int low = 0;
        int high = nums.size()-1;
        int closest = -1;
        int ans = nums.size();

        while (low<=high){
            int mid = low + (high-low)/2;
            if (nums[mid] >= target) {
                ans = mid;
                high = mid-1;
            }

            else { low = mid+1; }
            
        }

        return ans;
    }
};