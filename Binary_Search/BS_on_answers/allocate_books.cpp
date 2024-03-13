//Coding ninjas allocate books
int countStudents(const vector<int>& arr, int pages) {
    int students = 1;
    int currentPageSum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (currentPageSum + arr[i] > pages) {
            currentPageSum = arr[i];
            students++;
        } else {
            currentPageSum += arr[i];
        }
    }

    return students;
}



int findPages(vector<int>& arr, int n, int m) {
    int res = -1;
   
    if (m>n) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while (low <= high) {
        int mid = (low+high)/2;
        int students = countStudents(arr, mid);

        if (students>m) low = mid+1;
        else high = mid - 1;
    }

    return low;
}

int findPages(vector<int>& arr, int n, int m) {
    int res = -1;

    if (m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);

        if (students <= m) {
            res = mid;  // Update res if the current allocation is valid
            high = mid - 1;  // Explore lower allocation
        } else {
            low = mid + 1;  // Explore higher allocation
        }
    }

    return res;
}
// ^ using res 
