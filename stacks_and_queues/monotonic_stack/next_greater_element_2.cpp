// Leetcode 503. Next Greater Element II
// in this, we can cyclically search to find nge, unlike the first variation 

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n);

        for (int i=2*n-1; i>=0; i--) {
            while (!s.empty() && s.top()<=nums[i%n]) s.pop();
            ans[i%n] = (s.empty()) ? -1 : s.top();
            s.push(nums[i%n]);
        }

        return ans;
    }
};


// basically the same code as NGE 1, but we "copy" the array (virtually ,just by using indicing), 
// and take it twice
// replace i with i%n for circular array, and i goes from 2n-1 to 0