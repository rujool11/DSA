//  Leetcode 493. Reverse Pairs
class Solution {
private: 
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;      
    int right = mid + 1;   

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
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
}

int countPairs(vector<int> &arr,int low,int mid,int high){
    int right = mid+1;
    int counter = 0;

    for (int i=low;i<=mid;i++){
        while (right<=high && arr[i]>2*arr[right]) {right++;}
        counter += (right-(mid+1)); // right - (mid+1), since first el that does not satisfy this is to not be included
    }
    return counter;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int counter = 0;
    if (low >= high) return counter;
    int mid = (low + high) / 2 ;
    counter += mergeSort(arr, low, mid);  
    counter += mergeSort(arr, mid + 1, high); 
    counter += countPairs(arr,low, mid, high);
    merge(arr, low, mid, high);
    return counter;
}
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};


------------------------------------------------------------------------------------------------------------------------
// Submission - needed to use long long for submission

class Solution {
private: 
    void merge(vector<int> &arr, long long low, long long mid, long long high) {
        vector<int> temp; 
        long long left = low;      
        long long right = mid + 1;   

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
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

        for (long long i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    long long countPairs(vector<int> &arr,long long low,long long mid,long long high){
        long long right = mid+1;
        long long counter = 0;

        for (long long i=low;i<=mid;i++){
            while (right<=high && arr[i]>static_cast<long long>(2)*arr[right]) {right++;}
            counter += (right-(mid+1));
        }
        return counter;
    }

    long long mergeSort(vector<int> &arr, long long low, long long high) {
        long long counter = 0;
        if (low >= high) return counter;
        long long mid = (low + high) / 2 ;
        counter += mergeSort(arr, low, mid);  
        counter += mergeSort(arr, mid + 1, high); 
        counter += countPairs(arr,low, mid, high);
        merge(arr, low, mid, high);
        return counter;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
