vector<int> revArr(int start, int end, vector<int> &nums){
    
    if (start==end) {return nums;}
    else if (start+1==end) {
        swap(nums[start], nums[end]);
        return nums;
    }

    swap(nums[start], nums[end]);
    return revArr(start+1, end-1, nums);

}

vector<int> reverseArray(int n, vector<int> &nums) {
    return revArr(0, n - 1, nums);
}
