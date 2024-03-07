// Leetcode 1011. Capacity to ship packages within D days 
class Solution {
public:

    int daysNeeded(vector<int>& weights, int capacity) {
        int days = 1;
        int weightLoaded = 0;

        for (int i=0; i<weights.size();i++){

            if (weightLoaded+weights[i]>capacity){
                days++;
                weightLoaded = weights[i];
            }
            else {
                weightLoaded += weights[i];
            }
        }

        return days;
    }

    int asum(vector<int>& weights){
        int sum = 0;
        for (auto x: weights) sum += x;
        return sum;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN;
    
        for (auto x: weights){ 
            low = max(low, x);
        } // since should be able to carry at least 1

        int high = asum(weights); // sum of all weights will be the max
        // since that is the biggest value it needs to take (everything in 1 day)

        int res = -1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (daysNeeded(weights, mid) <= days){
                res = mid;
                high = mid - 1;
            }

            else low = mid + 1;
        }

        return res;

    }
};