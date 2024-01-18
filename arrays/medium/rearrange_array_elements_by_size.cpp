class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1;
        //easy soln --> make 2 arrays and merge
        vector<int> res(nums.size(),0);


        for (int i=0;i<nums.size();i++){
            if (nums[i]<0){
                res[neg] = nums[i];
                neg+=2;
            }

            else{
                res[pos] = nums[i];
                pos+=2;
            }
        }
        return res;
    }
};
