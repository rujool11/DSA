//Kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxHere = 0;
        int maxTotal = INT_MIN;

        for (int i=0;i<nums.size();i++){
            maxHere += nums[i];
            if (maxHere>maxTotal) {maxTotal = maxHere;}
            if (maxHere<0) {maxHere = 0;}
        }

        return maxTotal;
    }
};
