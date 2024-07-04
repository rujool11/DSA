// Leetcode 57. Insert interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;
        int start = newInterval[0];
        int end = newInterval[1];

        while (i < n && intervals[i][1] < start) { // left of ovrelapping
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= end) { // overlapping
            start = min(intervals[i][0], start); // start is min of all starts
            end = max(intervals[i][1], end); // end is max of all ends
            i++;
        }
 
        res.push_back({start, end}); // add overlapping

        while (i < n) { // after overlapping
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};