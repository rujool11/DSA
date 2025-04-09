void insertionSort(int arr[], int n) {
    for (int i=1;i<n;i++){
        int j=i;
        while (arr[j]<arr[j-1] && j>0){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp; // swap arr[j-1] and arr[j]
            j--;
        }
    }
}

// in each iteration, insert one element in its correct position
// from 0 to i, if arr[x] < arr[x-1], swap them and j--
