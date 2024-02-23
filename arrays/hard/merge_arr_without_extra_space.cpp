// Leetcode 88. Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int left = m-1;
        int right = 0;

        while (left>=0 && right<n){
            if (nums1[left] > nums2[right]){
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }

            else {break;}
        }

        // given - nums1 has size (m+n), so removing the last n elements
        // (for this method)

        for (int i=0;i<n;i++){
            nums1.pop_back();
        }

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        
    }

};


// Gap method -- Look up
