// Coding ninjas count inversions
int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;      
    int right = mid + 1;   
    int counter = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        // right is smaller, so increment counter
        else {
            counter += (mid - left + 1);
            temp.push_back(arr[right]);
            right++;
        }
    }


    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return counter;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int counter = 0;
    if (low >= high) return counter;
    int mid = (low + high) / 2 ;
    counter += mergeSort(arr, low, mid);  
    counter += mergeSort(arr, mid + 1, high); 
    counter += merge(arr, low, mid, high);
    return counter;
}

int numberOfInversions(vector<int>&a, int n) {
    return mergeSort(a, 0, n-1); // 
}