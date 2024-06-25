// Leetcode 1248. Count number of nice subarrays

class Solution {
public:

    int f(vector<int>& nums, int k) {
        if (k<0) return 0;
        int left = 0, right = 0, count = 0;
        int sum = 0;

        while (right < nums.size()) {
            sum += (nums[right]%2);

            while (sum > k) {
                sum -= (nums[left]%2);
                left++;
            }

            count += (right - left + 1);
            right++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // same as binary subarray with sum
        // just use nums[x] % 2 instead of nums[x], to keep sum as number of odd nos. 
        return f(nums, k) - f(nums, k-1);
    }
};