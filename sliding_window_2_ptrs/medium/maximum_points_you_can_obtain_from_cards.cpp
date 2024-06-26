// Leetcode 1423. Maximum points you can obtain from cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // to find arrays at start and end that have max sum
        // i.e. to find a subarray of length n-k that has min sum

        // to find min sum subarray of given length

        int totalSum = 0;
        for (int x: cardPoints) totalSum += x;
        int n = cardPoints.size();
        int minSum = INT_MAX;
        int sum = 0;
        int left = 0, right = 0;

        // sliding window of length n-k
        while (right < n) {
            sum += cardPoints[right];

            if (right - left + 1 > n - k) {
                sum -= cardPoints[left];
                left++;
            }

            if (right - left + 1 == n - k) minSum = min(minSum, sum);
            right++;
        }

        return totalSum - minSum;
    }
};


