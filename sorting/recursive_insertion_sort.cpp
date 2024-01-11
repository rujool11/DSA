void insertion_sort(int arr[], int i, int n) {

    if (i == n) return;

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
	swap(arr[j],arr[j-1]);
        j--;
    }

    insertion_sort(arr, i + 1, n);
}
