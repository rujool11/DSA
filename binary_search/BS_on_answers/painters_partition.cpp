// Coding ninjas painters partition
// Exactly similar to book allocation and split array largest sum

int count(vector<int> &boards, int mid){

    int painters = 1;
    int painterUnits = 0;

    for (int i=0;i<boards.size();i++){
        if (painterUnits+boards[i]<=mid) painterUnits+=boards[i];
        else{
            painters++;
            painterUnits = boards[i];
        }
    }

    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int res = -1;
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);

    while (low<=high)
    {
        int mid = low + (high-low)/2;
        int x = count(boards,mid);

        if (x<=k) {
            res = mid;
            high = mid -1;
        }
        else low = mid + 1;
    }

    return res;

}