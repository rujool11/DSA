// Leetcode 496. Next Greater Element 
// Brute Force solution --> 

class Solution {
public:

    int nge(int num, vector<int>& x) {
        int i = 0;
        for (i=0;i<x.size();i++){
            if (num==x[i]) break;
        }

        for (int j=i;j<x.size(); j++) {
            if (x[j] > num) return x[j];
        }

        return -1;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nge(num, nums2));
        }

        return ans;
    }
};

//------------------------------------------------------------------------------------------------------
// Monotonic stack solution --> 
// (continue from here)

