class Solution {
public:

    bool checkCount(vector<int>& bloomDay, long long day, long long m, long long k){

        long long adjGroups = 0;
        long long kCount = 0;

        for (long long i=0; i<bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                kCount++;
                if (kCount == k) {
                    adjGroups++;
                    kCount = 0;
                }
            }
            else 
                kCount = 0;
        }

        return adjGroups >= m;
    }

    pair<int,int> extremes(vector<int>& bloomDay){
        pair<int,int> res;
        res.first = INT_MAX;
        res.second = INT_MIN;
        for (auto x: bloomDay) {
            res.first = min(res.first, x);
            res.second = max(res.second, x);
        }

        return res;
    }

    long long minDays(vector<int>& bloomDay, long long m, long long k) {
        long long low = extremes(bloomDay).first;
        long long high = extremes(bloomDay).second;
        long long res = -1;
        long long val = m*k;

        if (val > bloomDay.size()) return -1; // impossible

        while (low <= high){
            long long mid = low + (high - low) / 2;
            if (checkCount(bloomDay, mid, m, k)) {
                res = mid;
                high = mid - 1;
            }
            else  
                low = mid + 1;
        }
        return res;
    }
};