//GFG number of platforms for train

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // sort all starting and departure times
        // for any given train, start and end will not be at same index after sorting
        // but, this doesnt matter since we are interested only in how many trains
        // are in platform at a particular time
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int platform = 1, result = 1; // since min 1 platform needed
        int arr_iter = 1, dep_iter = 0;
        // start at second arrival train, and first depature train
        // assume 1st train has already arrived

        // basically, increment at all arrivals, and decrement at all departures
        // update result when platform is greater than current value of result
        
        while (arr_iter < n && dep_iter < n) {
            
            if (arr[arr_iter] <= dep[dep_iter]) {
                platform++;
                arr_iter++;
            }
            
            else if (arr[arr_iter] > dep[dep_iter]) {
                platform--;
                dep_iter++;
            }
            
            // max overlapping will give minimum platforms
            if (platform > result) result = platform;
            
        }
        
        return result;
    }
};
