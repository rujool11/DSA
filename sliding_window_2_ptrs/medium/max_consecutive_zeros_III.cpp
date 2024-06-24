// Leetcode 1004. Max consecutive Ones III

class Solution {
public:
    int max(int a, int b) { return (a>b) ? a : b; }

    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int count = 0;
        int maxCount = 0;
        int zeros = 0;

        while (right < nums.size()) {
            
            if (nums[right] == 0) zeros++;

            if (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            
            if (zeros <= k) {
                maxCount = max(right - left + 1, maxCount);
            }

            right++;
        }
            
        return maxCount;
    }
};