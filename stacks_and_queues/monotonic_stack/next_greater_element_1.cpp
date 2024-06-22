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

class Solution {
public:
    vector<int> nge(vector<int>& x) {
        vector<int> ans(x.size());
        stack<int> s;

        // Traverse from right to left -> 
        // if stack is empty, current elements nge is -1
        // while top of stack is less than current element, pop it out
        // when we reach an element thats greater, it is the nge, else -1  if stack becomes empty
        // push current element onto the stack 
        // this ensures that the elements are pushed onto the stack in a sorted manner, with 
        // the largest elements at the bottom, and smaller els at top (ascending from top to bottom) 

        for (int i=x.size()-1; i>=0; i--) {
            while (!s.empty() && s.top()<=x[i]) s.pop();
            // if stack is not empty, and top el is less than curr, pop

            ans[i] = (s.empty()) ? -1 : s.top(); // if stack empty, -1 else top
            s.push(x[i]);
        }

        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> nge_2 = nge(nums2);
        unordered_map<int,int> hash;

        // keep a hash mapping from element in num2 to its nge
        for (int i=0; i<nums2.size(); i++) {
            hash[nums2[i]] = nge_2[i]; 
        }

        for (int num : nums1) {
            ans.push_back(hash[num]);
        }

        return ans;
    }
};