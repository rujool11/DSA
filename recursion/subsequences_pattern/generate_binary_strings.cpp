// GFG : Generate Binary Strings

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<string> generateBinaryStrings(int num){
        
        if (num==0) return {""};
        
        vector<string> prev = generateBinaryStrings(num-1);
        vector<string> ans;
        
        for (string x: prev){
            ans.push_back("0" + x);
            if (x[0]!='1'){
                ans.push_back("1" + x);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends