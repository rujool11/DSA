// Leetcode 2035. Partition Array Into Two Arrays to Minimize Sum Difference


// own recursion try (NOT CORRECT, FAILS) -->

class Solution {
    public:
        int getMinAbsDiff(vector<int>& nums, int sum1, int sum2, int idx, int len1, int len2) {
            if (idx == 0) {
                int putinone = abs(sum1 + nums[0] - sum2);
                int putintwo = abs(sum1 - (nums[0] + sum2));
    
                if (len1 < len2) return putinone;
                if (len2 < len1) return putintwo;
                else return (min(putinone, putintwo));
    
            }
    
            // sum1 += nums[idx];
            // len1++;
            // int leftmin = getMinAbsDiff(nums, sum1, sum2, idx-1, len1, len2);
            // sum1 -= nums[idx];
            // len1--;
            // sum2 += nums[idx];
            // len2++;
            // int rightmin = getMinAbsDiff(nums, sum1, sum2, idx-1, len1, len2);
            int leftmin = 1e9;
            int rightmin = 1e9;
    
            if (len1 - len2 == 1) {
                // can put in left
                leftmin = getMinAbsDiff(nums, sum1+nums[idx], sum2, idx-1, len1+1, len2);
            }
    
            else if (len2 - len1 == 1)  {
                // can put in right
                rightmin = getMinAbsDiff(nums, sum1, sum2+nums[idx], idx-1, len1, len2+1);
            }
    
            else if (len1 == len2) {
                // can put in both
                leftmin = getMinAbsDiff(nums, sum1+nums[idx], sum2, idx-1, len1+1, len2);
                rightmin = getMinAbsDiff(nums, sum1, sum2+nums[idx], idx-1, len1, len2+1);
            }
    
            else {
                // cannot proceed
            }
            
            return min(leftmin, rightmin);
        }
    
        int minimumDifference(vector<int>& nums) {
        
            int n = nums.size();
            // moth arrays should have same size
            return getMinAbsDiff(nums, 0, 0, n-1, 0, 0);
        }
    };