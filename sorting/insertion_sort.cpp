void insertionSort(int arr[], int n)
{
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
