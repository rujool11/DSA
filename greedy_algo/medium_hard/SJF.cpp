// GFG SJF 
// to return average waiting time

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end(), [](int& a, int&b){ return b>a;});
        
        long long res = 0.0;
        long long sum = bt[0];
        int n = bt.size();
        
        for (int i=1; i<n; i++) {
            res += sum;
            sum += bt[i];
        }
        
        return res/n;
    }
};