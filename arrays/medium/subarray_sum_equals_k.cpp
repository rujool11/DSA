class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> hash;
        int sum = 0;
        int count = 0;
        hash[0] = 1;
        // solved using prefix sum

        for (int i=0;i<nums.size();i++){

            sum += nums[i]; // current prefix sum
            count += hash[sum-k]; //number of subarrays with sum sum-k
            hash[sum]++; // increment sum 
        
        }

        return count;

    }
};
