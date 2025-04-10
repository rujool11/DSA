// quick sort ->
// pick a pivot element and place it in its correct position in sorted array
// place elements smaller than pivot to its left and elements larger than pivot to its right

class Solution {
public:
    // Partition function: chooses the first element as pivot
    // and rearranges the array such that all elements <= pivot
    // are on the left, and elements > pivot are on the right.
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int i = low; 
        int j = high;

        while (i < j) {
            while (nums[i] <= pivot && i<=high) i++;
            while (nums[i] > pivot && j>=low) j--;

            if (i<j) swap(nums[i], nums[j]);
        }

        swap(nums[low], nums[j]); // j is the correct pivot position
        return j;
    }

    void qs(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(nums, low, high);
            qs(nums, low, pivotIndex - 1);
            qs(nums, pivotIndex + 1, high);
        }
    }

    vector<int> quickSort(vector<int>& nums) {
        qs(nums, 0, nums.size() - 1);
        return nums;
    }
};

// idea -> each element arranges themselves
// eg. students in a class heightwise order
// shortest goes at the start, tallest at the end
// remaining arrange themselves
// pivot compares with people beside them
// if taller at front, shorter at back, then swap
