// Coding ninjas, ceil the floor
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	pair<int,int> p;

	int low = 0;
	int high = n-1;
	int floor = -1;

	while (low<=high){
		int mid = low + (high-low)/2;
		if (arr[mid] <= x){
			floor = arr[mid];
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}

	p.first = floor;

	low = 0;
	high = n-1;
	int ceil = -1;

	while (low<=high){
		int mid = low + (high-low)/2;
		if (arr[mid] >= x){
			ceil = arr[mid];
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}

	p.second = ceil;
	return p;
	
}
