// GFG Better string
// give string with more number of distinct subsequences
// Recursion/ backtracking solution -> ideally, will be optimized using dp


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void findSubs(set<string>& subs, string& helper, string x, int index ){
        if (index==x.size()){
            subs.insert(helper);
            return;
        }
        
        helper += x[index];
        findSubs(subs, helper, x, index+1);
        
        helper.pop_back();
        findSubs(subs, helper, x, index+1);
    }
  
    int distinctSubsequences(string x){
        set<string> subs;
        string helper="";
        findSubs(subs, helper, x, 0);
        return subs.size();
    }
    string betterString(string str1, string str2) {
        if (distinctSubsequences(str1) >= distinctSubsequences(str2)) return str1;
        
        return str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends