// Coding ninjas Aggressive cows
bool canPlace(vector<int> &stalls, int x, int k){
    int count = 1;
    int last = stalls[0];

    for (int i=1;i<stalls.size();i++){
        if (stalls[i]-last >= x) {
            count++;
            last = stalls[i];
        }

        if (count>=k) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    // closest 2 cows should be as far off as possible
    sort(stalls.begin(),stalls.end());
    int res = -1;

    int low = 1; 
    int high = stalls[stalls.size()-1] - stalls[0]; 
    //^ max min dist can at max be the max difference between extremes

    //mid/x in canPlace function is min distance between 2 cows

    while (low<=high) {
        int mid = low + (high-low)/2;

        if (canPlace(stalls,mid,k)) {
            res = mid;
            low = mid+1;
        }
        else high = mid - 1;
    }

    return res;


}