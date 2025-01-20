#include <bits/stdc++.h>
using namespace std;

int fibo_memo(int n, vector<int>& dp) {
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];

    return dp[n] = fibo_memo(n-1, dp) + fibo_memo(n-2, dp);
}

int fibo_tabulation(int n) {
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int fibo_tabulation_optimized_space(int n) {
    int prev1 = 1;
    int prev2 = 0;
    int curr = 0;

    for (int i=2; i<=n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main() {

    int n;
    cin>>n;
    vector<int> dp(n+1, -1);

    cout << fibo_memo(n, dp) << endl;
    cout << fibo_tabulation(n) << endl;
    cout << fibo_tabulation_optimized_space(n) << endl;
}