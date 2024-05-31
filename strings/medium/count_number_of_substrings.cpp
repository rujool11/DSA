// GFG count substrings with k distinct characters
// count substrings, not necessarily unique, that have k distinct charcters

class Solution
{
  public:
    
    long long int subC(string s, int n, int k){
        
        int freq[26] = {0};
        int distinct = 0;
        long long int count = 0;
        int i=0, j=0;
        
        for (i=0;i<n;i++){
            while (j<n && distinct<k){
                freq[s[j]-'a']++;
                if (freq[s[j]-'a'] == 1) distinct++;
                j++;
            }
            
            if (distinct>=k) count += (n-j+1);
            freq[s[i]-'a']--;
            if (freq[s[i]-'a']==0) distinct--;
        }
        
        return count;
    }
  
    long long int substrCount (string s, int k) {
    	long long int ans;
    	int n = s.size();
    	ans = subC(s,n,k) - subC(s,n,k+1);
    	return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}