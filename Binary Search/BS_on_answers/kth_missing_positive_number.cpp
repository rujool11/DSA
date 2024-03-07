// Leetcode 1539. Kth missing positive integer
// Brute Force solution
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //Brute force O(n)
        // numbers <= k will take its place
        for (int i=0;i<arr.size();i++){
            if (arr[i]<=k) k++;
            else break;
        }

        return k;
    }
};

// Check out Math + B.S. solution later