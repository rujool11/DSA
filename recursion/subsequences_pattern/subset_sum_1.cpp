// Geeks for Geeks Subset Sums
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void doStuff(vector<int>& ans, int& v_s, vector<int> arr, int n, int index){
        if (index==n) {
            ans.push_back(v_s);
            return;
        }
        
        v_s += arr[index];
        doStuff(ans, v_s, arr, n, index+1);
        
        v_s -= arr[index];
        doStuff(ans, v_s, arr, n, index+1);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        int v_s = 0;;
        
        doStuff(ans, v_s, arr, n, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends