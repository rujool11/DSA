// Leetcode 70. Climbing stairs

class Solution {
public:
    int climbStairs(int n) {
        // at each step, we could either have come from step n-1 (1 step) or step n-2 (2 steps)
        // d[n] = d[n-1] + d[n-2]
        // basically fibonacci
        // this is the space and time optimized solution

        if (n == 0 || n == 1) return 1;

        int prev1 = 1, prev2 = 1;
        int res = 0;

        for (int i=2; i<=n; i++) {
            res = prev1 + prev2;
            prev2 = prev1;
            prev1 = res;
        } 

        return res;
    }
};