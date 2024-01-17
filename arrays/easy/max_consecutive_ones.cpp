class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int i = -1;
        int max = 0;
        for (int p=0;p<nums.size();p++){
            if (nums[p]==1) {i=p;break;}
        }

        if (i==-1){return 0;}

        for (int j=i+1;j<nums.size();j++){
            if (nums[j]==1) {continue;}

            else {
                max = j-i;
                if (max>res) {res=max;}
                i = j+1;
            }
        }

        max = nums.size() - i;
        if (max>res) {res=max;}

        return res;

    }
};
