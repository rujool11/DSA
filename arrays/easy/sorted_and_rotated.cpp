class Solution {
public:
    bool check(vector<int>& nums) {
        bool isRotated = false;
        int n = nums.size();
        for (int i=1;i<n;i++) {
            if (nums[i-1]>nums[i]){
                if (!isRotated) { isRotated = true;}
                else {return false;}
            }
        }

        if (nums[n-1]>nums[0] && isRotated) { return false;}
	//remember to check for this condition, if start index is greater and array has already been rotated

        return true;
    }
};
