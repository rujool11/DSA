int removeDuplicates(vector<int> &arr, int n) {
	int count = 1;
	for (int i=1;i<n;i++){
		if (arr[i-1]==arr[i]) {continue;}
		count++;
	}
	// alternatively, use hashmap 
	return count;
}

// above solution is just for finding out number of elements in array, look below for in place sorting by using two pointer solution


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for (int j=1;j<nums.size();j++){
            if (nums[i]!=nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;
    }
};
