// Leetcode 992. subarrays with k different integers
// to COUNT number of subarrays with EXACTLY k distinct integers
 
// at_most(k) - at_most(k-1)

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithatmostKDistinct(nums, k) - subarraysWithatmostKDistinct(nums, k-1);
    }

    int subarraysWithatmostKDistinct(vector<int>& nums, int k) {
        if (k<=0) return 0;
        unordered_map<int,int> hash;
        int left = 0, right = 0;
        int ans = 0;

        while (right < nums.size()) {
            hash[nums[right]]++;

            while (hash.size() > k) {
                hash[nums[left]]--;
                if (hash[nums[left]] == 0) hash.erase(nums[left]);
                left++;
            }

            ans += (right - left + 1); // since we can create r - l + 1 new subarrays with new element
            right++;
        }

        return ans;
    }
};