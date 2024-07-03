// GFG n meetings in one room

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    // only one meeting at a time
    int maxMeetings(int start[], int end[], int n)
    {
       vector<pair<int,int>> meetings(n);
       for (int i=0; i<n; i++) meetings[i] = {start[i], end[i]};
       
       // sort by end time
       sort(meetings.begin(), meetings.end(), [](pair<int,int>& a, pair<int,int>&b) {
           return a.second < b.second;
       } );
       
       int count = 1; // since at least one can be held
       int last_end_time = meetings[0].second;
       
       for (int i=1; i<n; i++) {
           if (meetings[i].first > last_end_time) { // .first is start time, .second is end time
               count++;
               last_end_time = meetings[i].second;
           }
       }
       
       return count;
    }
};