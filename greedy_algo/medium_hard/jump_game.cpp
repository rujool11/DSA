// Leetcode 55. Jump game  
// can reach last index or not ? 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0; // max index we can reach at any index
        for (int i=0; i<nums.size(); i++) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= nums.size() - 1) return true; // exceed max index at any position
        }

        return true;
    }
};

// keep track of the farthest position we can reach 
// if current index beyond maxReach, return false
// if at any point maxReach becomes more than last index, return true
// update maxReach to max of its current value, and possible greatest at 
// any index (i + nums[i])