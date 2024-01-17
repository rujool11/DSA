class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(),nums.end());
    }
};

// optimal solution without using any extra memory
// remember vector.end() points to one past last filled memory address
