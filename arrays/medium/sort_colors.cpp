class Solution {
public:
    void sortColors(vector<int>& nums) {
        // can just count and insert in array, but to do in place 
        // bring zeros to left and twos to right
        // DNF algo - Dutch National Flag
        
        int low = 0, mid = 0, high = nums.size()-1;

        while (mid<=high){
            if (nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if (nums[mid]==1){
                mid++;
            }

            else if (nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
