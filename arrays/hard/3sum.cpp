// Leetcode 15. 3Sum

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res; // used set so no repeats

        for (int i=0;i<nums.size();i++){
            set<int> hash;
            for (int j=i+1;j<nums.size();j++){
                int rem = -(nums[i]+nums[j]);

                if (hash.find(rem)!=hash.end()){
                    vector<int> temp = {nums[i], nums[j], rem};
                    sort(temp.begin(),temp.end());
                    hash.insert(nums[j]);
                    res.insert(temp);

                }

                hash.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(res.begin(),res.end());
        return ans;

    }

}; // set used to avoid repeats, copied to vector, O(n^2logn) time complexity, since 2 loops and set used
// sorting is on constant space, so constant time


//Optimal solution

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> res;

       sort(nums.begin(), nums.end()); // O(nlogn)

       for (int i=0;i<nums.size();i++){

           if (i>0 && nums[i]==nums[i-1]) {continue;} // if same as before, skip
           // i>0 used to ensure that it is not the first element

           int j = i+1;
           int k = nums.size()-1;

            while (j<k){
                int sum = nums[i] + nums[j] + nums[k];

                if (sum<0){j++;}
                else if (sum>0){k--;}
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    res.push_back(temp);
                    j++;
                    k--;
                    while (j<k && nums[j]==nums[j-1]){j++;} // skip came j and k values
                    while (j<k && nums[k]==nums[k+1]){k--;}
                }
            }

       }

       return res;
    }

};