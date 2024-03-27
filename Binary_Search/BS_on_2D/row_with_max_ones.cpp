// Coding ninjas find row with max ones 
// lower bound of 1 will give the first occurence of 1
// m - lb(1) => no. of ones in a particular row since sorted 
// update only when > since when same number of rows, lower index is to be returned
int lowerBound(vector<int> &row, int x){
    int low = 0;
    int high = row.size()-1;
    int res = row.size();

    while (low<=high){
        int mid = low + (high-low)/2;

        if (row[mid] >= x){
            res = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    return res;
}


int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int maxCount = -1;
    int maxIndex = -1;

    // m - first occurence (lower bound) (since sorted inner arrays)

    for (int i=0;i<n;i++){
        int ones = m - lowerBound(matrix[i], 1 );
        if (ones > maxCount) {
            maxCount = ones;
            maxIndex = i;
        }
    }

    return maxIndex;
}