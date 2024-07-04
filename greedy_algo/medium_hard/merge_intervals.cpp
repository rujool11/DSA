// Leetcode 56. Merge intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>> res;

       sort(intervals.begin(), intervals.end());

       for (int i=0; i<intervals.size(); i++) {
            // no need to merge if end of last one is less than start of current
            if (res.empty() || res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            }
            // need to merge when above condition is not true
            // just update end of last one with whichever end is maximum 
            else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
       }

       return res;
    }
};