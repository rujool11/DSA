class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> hash;
        int sum = 0;
        int count = 0;
        hash[0] = 1;
        // solved using prefix sum

        for (int i=0;i<nums.size();i++){

            sum += nums[i];
            count += hash[sum-k];
            hash[sum]++;
        
        }

        return count;

    }
};
