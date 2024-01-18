class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        int longest = 1;

        if (nums.size()==0) {return 0;}

        for (auto num: nums){
            uset.insert(num);
        }

        for (auto it: nums){
            if (uset.find(it-1)==uset.end()){
                int count = 1;
                int x = it;
                while (uset.find(x+1)!=uset.end()){x++;count++;}
                longest = max(count,longest);
            }
        }

        return longest;
    }
};
