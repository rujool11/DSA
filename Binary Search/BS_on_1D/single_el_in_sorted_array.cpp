// Leetcode 540. Single element in sorted array
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // edge cases
        if (nums.size() == 1) return nums[0]; 
        if (nums[0] != nums[1]) return nums[0]; 
        if (nums[nums.size()-1] != nums[nums.size()-2])  return nums[nums.size()-1];
        
        int low = 1;
        int high = nums.size()-2;

        while (low<=high){
            int mid = low + (high-low)/2;
            
            //check if mid is the single element
            if (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) return nums[mid];

            //check if we are in the left half, i.e el in right half, eliminate left half
            /*
            condition 1 -> we are on odd index & el is equal to its previous
            condition 2 -> we are on even index & el is equal to its next
            this is since { (even,odd) pairs, single el, (odd,even) pairs} is array structure
            both of these denote that we are on the left half, and single el has not
            occured yet. So, eliminate left half
            */
            if ((mid%2==1 && nums[mid] == nums[mid-1])
            || (mid%2==0 && nums[mid] == nums[mid+1])) {
                low = mid+1;
            }

            // else we are on the right half and el has occured, so eliminate right half    
            else{
                high = mid-1;
            }
        }

        return -1;
    }
};