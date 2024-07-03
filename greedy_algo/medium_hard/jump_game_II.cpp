// Leetcode 45. jump game II


class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int left = 0, right = 0;

        while (right < nums.size()-1) {
            int farthest = 0;
            for (int i=left; i<=right; i++) farthest = max(farthest, i + nums[i]);
            left = right + 1;
            right = farthest;
            jumps++;
        }

        return jumps;
    }
};


// time complexity O(n) since each index is processed at max only once, even tho
// for loop inside while