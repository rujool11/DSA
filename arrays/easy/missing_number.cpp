class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> map;

        for (auto i: nums){map[i]=1;}

        for (int i=0;i<nums.size()+1;i++){
            if (map.find(i)==map.end()){return i;}
        }

        return -1;
    }
};

// can do with sum of integers property to avoid one extra loop and same space
