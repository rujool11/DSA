class Solution {
public:
    int singleNumber(vector<int>& nums) {
       unordered_map<int,int> map;
       for (auto num: nums){
           map[num]++;
       } 

       for (auto it: map){
           if (it.second==1){return it.first;}
       }

       return -1;
    }
};


//optimal solution using xor
//same time complexity, but no additional space and less operations

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int x = 0;
       for (auto num: nums){
           x = x^num;
       }

       return x;
    }
};
