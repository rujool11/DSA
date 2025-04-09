void selectionSort(vector<int> &arr) {
    int n = arr.size();
    int min;

    for (int i=0;i<n-1;i++){

        min = i;

        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[min]) {min=j;}
        }
        swap(arr[i],arr[min]);
    }
}

// in each iteration, select the smallest element 
// from i to the end, and swap it with i
