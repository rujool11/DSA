// Coding ninjas lower bound
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low = 0;
	int high = n-1;
	int ans = n; // if all numbers are smaller than x, then x is the bound
	
	// smallest index such that a[i] >= x

	while (low<=high){
		int mid = low + (high-low)/2;

		if (arr[mid] >= x){
			ans = mid;
			high = mid - 1;
		}

		else{
			low = mid + 1;
		}
	}

	return ans;
}