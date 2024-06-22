// Leetcode 3. Longest substring without repeating characters


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       if (s.empty()) return 0;
    
       unordered_map<int, int> hash;
       for (int i=0; i<256; i++) hash[i] = -1;

       int left = 0, right = 0;
       int maxLen = INT_MIN;

        // hash of 256 used to account for all 256 characters possible
        // at any point, curr len = right - left + 1, update maxLen if needed, 
        // and set hash[s[right]] = right; (basically hash[curr] = curr_index)
        // increment right and continue

        // in case where curr is already present in hashmap, update left to 
        // hash[curr] + 1, BUT, only do this if hash[curr]+1 >= left
        // this is for the case where the character has been seen before, but 
        // before the start of current substring, in which case no updation needed

       while (right < s.size()) {

        if (hash[s[right]] != -1) left = max(hash[s[right]] + 1, left);

        int len = right - left + 1;
        maxLen = max(len, maxLen);
        hash[s[right]] = right;
        right++;
       }

       return maxLen;
    }
};