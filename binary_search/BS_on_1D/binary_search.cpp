// Leetcode 704. Binary search

class Solution {

    int binarySearch(vector<int> &arr, int low, int high, int target){
        if (low>high) {return -1;}

        int mid = low + (high-low)/2;

        if (arr[mid]==target) {return mid;}
        else if (arr[mid] > target) {return binarySearch(arr,low,mid,target);}
        else { return binarySearch(arr,mid+1,high,target);}

    }

public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};

// Iterative 

class Solution {

    int binarySearch(vector<int> &arr, int low, int high, int target){
        
        while (low<=high){
            int mid = low + (high-low)/2;
            if (arr[mid]==target) {return mid;}
            else if (arr[mid] > target) { high = mid -1 ;}
            else { low = mid + 1;}
        }

        return -1;

    }

public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};