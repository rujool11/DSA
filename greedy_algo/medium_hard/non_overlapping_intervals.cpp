// Leetcode 435. Non-overlapping intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // if same start and end, will not be considered overlapping
        // eg. (2,3) and (3,4) are not overlapping, for this question

        // similar to n meetings in 1 room where start and end times are the intervals
        // sort by "ending times" (2nd element)
        // if we figure out max number of meetings, the left out meetings are the answer

        // sort on basis of "end times" / 2nd element -> 
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 1;
        int last_end_time = intervals[0][1];
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] >= last_end_time) {
                count++;
                last_end_time = intervals[i][1];
            }
        }

        return intervals.size() - count;

    }
};