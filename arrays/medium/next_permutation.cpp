class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //next_permutation(nums.begin(),nums.end()); //in built STL function

        int dip = -1;
        for (int i=nums.size()-2;i>=0;i--){
            if (nums[i]<nums[i+1]){
                dip = i;
                break;
            }
        }

        if (dip==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for (int i=nums.size()-1;i>dip;i--){
            if (nums[i]>nums[dip]){
                swap(nums[i],nums[dip]);
                break;
            }
        }// doubt: first one that is greater or smallest one that is greater (first one that is greater done here)

        sort(nums.begin()+dip+1,nums.end());
    }
};
