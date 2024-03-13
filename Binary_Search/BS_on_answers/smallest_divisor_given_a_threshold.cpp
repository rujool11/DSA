// Leetcode 1282. Smallest divisor given a threshold
class Solution {
public:
    int getSum(vector<int>& nums, int d){
        int res = 0;
        for (auto x: nums){
            res += ceil((double)(x)/(double)(d));
        }
        return res;
    }

    int max(vector<int>& nums){
        int res = INT_MIN;
        for (auto x: nums) {
            if (x>res) {res=x;}
        } 
        return res;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int res = -1;
        int low = 1;
        int high = max(nums);

        while (low<=high){
            long long mid = low + (high-low)/2;

            int sum = getSum(nums,mid);
            if (sum<=threshold){
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return res;
    }
};