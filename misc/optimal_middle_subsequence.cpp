// given an array, find and the return the minimal sum of all possible
// triples (subsequences of length 3) arr[i], arr[j], arr[k] such that ->
// arr[i] < arr[j] > arr[k] (minimize the sum of this triple and return the sum) 
// if not possible, return -1

// naive solution ->
// iterate through arr keeping arr[j] as middle element
// find min at left, min at right, and then update minSum
// O(n^2)

#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int getMiddleSubsequenceSum(const vector<int>& s) {
    int n = s.size();
    int minSum = 1e9;
    
    for (int j = 1; j < n - 1; j++) {
        // find left smallest
        int leftCandidate = 1e9;
        for (int i = 0; i < j; i++) {
            if (s[i] < s[j])
                leftCandidate = min(leftCandidate, s[i]);
        }
        if (leftCandidate == 1e9) continue;  // no valid leftmin 
        
        // find right smallest
        int rightCandidate = 1e9;
        for (int k = j + 1; k < n; k++) {
            if (s[k] < s[j])
                rightCandidate = min(rightCandidate, s[k]);
        }
        if (rightCandidate == 1e9) continue;  // no valid right min
        
        // update min sum
        minSum = min(minSum, leftCandidate + s[j] + rightCandidate);
    }
    
    return (minSum == 1e9) ? -1 : minSum;
}

// optimized solution -> use prefix and suffix sums
// prefix min array instantly gives min element upto certain index before j
// suffix min array instantly gives min element of indices from j to end 
// O(n)


int getMiddleSubsequenceSum(const vector<int>& s) {
    int n = s.size();
    if(n < 3) return -1; // need subsequence of at least 3 
    
    // prefixMin[j] = min(s[0], s[1], ..., s[j])
    vector<int> prefixMin(n);
    prefixMin[0] = s[0];
    for (int j = 1; j < n; j++) {
        prefixMin[j] = min(prefixMin[j - 1], s[j]);
    }
    
    // suffixMin[j] = min(s[j], s[j+1], ..., s[n-1])
    vector<int> suffixMin(n);
    suffixMin[n - 1] = s[n - 1];
    for (int j = n - 2; j >= 0; j--) {
        suffixMin[j] = min(suffixMin[j + 1], s[j]);
    }
    
    int ans = 1e9;
    bool found = false;
    
    // go from i to n-1
    for (int j = 1; j < n - 1; j++) {
        // The best left candidate is prefixMin[j-1] if it is strictly less than s[j].
        int leftCandidate = prefixMin[j - 1];
        if(leftCandidate >= s[j]) continue; //  no valid left min
        
        // The best right candidate is suffixMin[j+1] if it is strictly less than s[j].
        int rightCandidate = suffixMin[j + 1];
        if(rightCandidate >= s[j]) continue; // no valid right min
        
        ans = min(ans, leftCandidate + s[j] + rightCandidate);
        found = true;
    }
    
    return found ? ans : -1;
}

