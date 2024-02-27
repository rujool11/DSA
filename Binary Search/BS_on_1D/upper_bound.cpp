int upperBound(vector<int> &arr, int x, int n){
    // first value i such that arr[i] > x
	int ans = n; // if none found , return n
	int low = 0;
	int high = n-1;

	while (low<=high){
		int mid = low + (high-low)/2;

		if (arr[mid] > x){
			ans = mid;
			high = mid -1;
		}
		else {
			low = mid + 1;
		}
	}	

	return ans;
}