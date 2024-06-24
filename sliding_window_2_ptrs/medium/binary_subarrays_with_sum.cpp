// Leetcode 930. Binary subarrays with sum 


// same solution as subarray sum equals k -->
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int sum = 0;
        unordered_map<int,int> hash;
        hash[0] = 1;

        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            count += hash[sum - goal];
            hash[sum]++;
        }

        return count;
    }
};


// optimized solution for binary array -->
class Solution {
public:

    int sumLesserOrEqualsK(vector<int>& nums, int goal) {
        if (goal < 0) return 0; // since we are calling (nums, goal-1) in main function
        int left = 0, right = 0, count = 0;
        long long sum = 0;

        while (right < nums.size()) {
            sum += nums[right];

            while (sum > goal) {
                sum -=  nums[left];
                left++;
            }

            count += (right - left + 1);
            right++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sumLesserOrEqualsK(nums, goal) - sumLesserOrEqualsK(nums, goal-1);
    }
};