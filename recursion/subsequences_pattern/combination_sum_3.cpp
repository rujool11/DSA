// Leetcode 216. Combination Sum III
class Solution {
public:
    void doStuff(vector<vector<int>>& ans, vector<int>& helper, vector<int>& arr, int k, int n, int index){
        
        if (index==arr.size()){
            if (helper.size()==k && n==0) ans.push_back(helper);
            return; 
        }
        
        if (helper.size()==k){
            if (n==0) ans.push_back(helper);
            return;
        }

        helper.push_back(arr[index]);
        doStuff(ans, helper, arr, k, n-arr[index], index+1);


        helper.pop_back();
        doStuff(ans, helper, arr, k, n, index+1);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> helper;
        vector<int> arr = {1,2,3,4,5,6,7,8,9};

        doStuff(ans, helper, arr, k, n, 0);
        return ans;
    }
};

//--------------------------------------------------------------------------------------------------------------------------
// Alternate solution


class Solution {
public:

    void doStuff(vector<vector<int>>& ans, vector<int>& helper,int k, int n, int index){
        
        if (helper.size()==k){
            if (n==0) ans.push_back(helper);
            return;
        }

        for (int i=index; i<=9; i++){
            helper.push_back(i);
            doStuff(ans, helper, k, n-i, i+1);
            helper.pop_back();
            // no need for another doStuff call here since that is taken care
            // of by next iterations
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> helper;
  
        doStuff(ans, helper, k, n, 1); // 1 since index itself is used as number, since no array
        return ans;
    }
};