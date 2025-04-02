// GFG subset sum equals target
// in given array return true if there is a subset with sum equal to target, else return false

// recursion solution 1 ->

bool hasValidSum(vector<int>& arr, vector<int>& helper, int target, int idx) {
    if (idx == arr.size()) return false;
    if (target == 0) return true;
    
    helper.push_back(arr[idx]);
    if (hasValidSum(arr, helper, target - arr[idx], idx + 1)) return true;
    helper.pop_back();
    if (hasValidSum(arr, helper, target, idx + 1)) return true;
    
    return false; 
}

bool isSubsetSum(vector<int>& arr, int sum) {
    vector<int> helper;
    return hasValidSum(arr, helper, sum, 0);
}

// recursion solution 2 ->

class Solution {
    public:
      bool hasValidSum(int idx, vector<int>& arr, int target) {
          if (target == 0) return true;
          if (idx == 0) return (arr[0] == target) ? true : false;
          
          bool nottake = hasValidSum(idx-1, arr, target);
          bool take = false;
          if (target >= arr[idx]) {
              take = hasValidSum(idx-1, arr, target-arr[idx]);
          }
          
          return take || nottake;
          
      } 
      
      bool isSubsetSum(vector<int>& arr, int sum) {
          
          return hasValidSum(arr.size()-1, arr, sum);
          
      }
  };


// both recursion solutions TLE at 10/1115 test cases

// memoization solution ->

class Solution {
    public:
      int hasValidSum(int idx, vector<int>& arr, int target, vector<vector<int>>& dp) {
          if (target == 0) return dp[idx][target] = 1;
          if (idx == 0) return dp[idx][target] = (arr[0] == target) ? 1 : 0;
          
          if (dp[idx][target] != -1) return dp[idx][target];
          
          int nottake = hasValidSum(idx-1, arr, target, dp);
          int take = 0;
          if (target >= arr[idx]) {
              take = hasValidSum(idx-1, arr, target-arr[idx], dp);
          }
          
          return dp[idx][target] = take || nottake;
          
      } 
      
      bool isSubsetSum(vector<int>& arr, int sum) {
          
          // denote -1 -> not visited
          // 0 -> false, 1 -> true
          // 2D dp since target is also variable in recursive calls
          vector<vector<int>> dp(arr.size(), vector<int>(sum+1, -1));
          // use sum + 1 since target == sum is initial call
          return (bool)hasValidSum(arr.size()-1, arr, sum, dp);
          
      }
  };

// tabulation solution ->

class Solution {
    public:
      bool isSubsetSum(vector<int>& arr, int sum) {
          int n = arr.size();
          vector<vector<int>> dp(n, vector<int>(sum+1, 0));
          
          // base cases easy to figure out from tabulation solution
          // if target == 0, then every idx gives true
          // if idx == 0, then itll give true for arr[0] being target as 
          for (int i = 0; i < n; i++) dp[i][0] = 1;  // Any subset can make sum = 0
          
          if (arr[0] <= sum) dp[0][arr[0]] = 1;  // Fix: Ensure arr[0] is within bounds
  
          for (int i = 1; i < n; i++) {
              for (int target = 1; target <= sum; target++) {
                  int notTake = dp[i-1][target];  
                  int take = 0;
                  if (arr[i] <= target) {
                      take = dp[i-1][target-arr[i]];  
                  } 
                  dp[i][target] = take || notTake;
              }    
          }
          
          return (bool) dp[n-1][sum];
      }
  };
