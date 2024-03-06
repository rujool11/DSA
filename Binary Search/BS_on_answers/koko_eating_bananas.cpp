// Leetcode 875. Koko eating Bananas
class Solution {
public:
    long long timeNeeded(vector<int>& piles, long long k) {
        long long time = 0;
        for (int i=0;i<piles.size();i++){
            time += ceil((double)piles[i]/(double)k); // important to add double to ensure correct ceil
        }

        return time;
    }

    long long minEatingSpeed(vector<int>& piles, long long h) {

        long long n = piles.size();
        
        long long max = LLONG_MIN;

        for (auto x: piles) {
            if (x>max) {max=x;}
        } // max element in array will always work 

        long long low = 1;
        long long high = max;
        long long ans = max;

        while (low<=high){
            long long mid = low + (high-low)/2;
            long long time = timeNeeded(piles,mid);
            if (time <= h) {
                ans = mid;
                high = mid-1;
            }

            else {low = mid+1;}

        }

        return ans;
    }
};