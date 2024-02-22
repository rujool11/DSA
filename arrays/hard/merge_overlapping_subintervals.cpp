// Brute Force --
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());
        // brute force solution, will sort array by first element

        for (int i=0;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];


            if (!res.empty() && res.back()[1]>=end){continue;} //skipped merged intervals
            
            for (int j=i+1;j<intervals.size();j++){
                if (end>=intervals[j][0]){
                    end = max(end, intervals[j][1]);
                }
                else{break;} // since sorted
            }

            res.push_back({start,end});

        }

        return res;
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(),intervals.end());

        for (int i=0;i<intervals.size();i++){

            if (res.empty() || intervals[i][0]>res.back()[1]){
                res.push_back(intervals[i]);
            } // if empty or not to be merged, add as is

            else{
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            // update [1] as needed according to whether or not merged
        }

        return res;
    }
};