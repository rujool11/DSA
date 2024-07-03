// GFG job scheduling

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // sort according to descending order of profit
        sort(arr, arr+n, [](Job& a, Job& b) {
            return a.profit > b.profit;
        });
        
        
        // try to perform every job on its last day to accomodate max jobs
        // the later we perform, better it will be
        
        int maxDeadline = INT_MIN;
        for (int i=0; i<n; i++) maxDeadline = max(maxDeadline, arr[i].dead);
        
        int profit = 0;
        int jobsDone = 0;
        vector<int> slots(maxDeadline+1, -1); // vector of -1s of size maxDeadline
        // maxDeadline + 1 since 1-indexed^
        
        for (int i=0; i<n; i++) {
            // j>0 since deadlines start from 1st day, so effectively 1-indexed
            for (int j=arr[i].dead; j>0; j--) {
                if (slots[j] == -1) {
                    slots[j] = i;
                    profit += arr[i].profit;
                    jobsDone++;
                    break;
                }
            }
        }
        
        return {jobsDone, profit};
    } 
};