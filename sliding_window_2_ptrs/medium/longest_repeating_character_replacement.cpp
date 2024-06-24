// Leetcode 42. Longest repeating character replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0, right = 0;
        int maxFreq = 0;
        int maxLen = 0;
        
        unordered_map<int,int> hash; // to store frequencies

        while (right < s.size()) {

            hash[s[right] - 'A']++;
            maxFreq = max(maxFreq, hash[s[right]-'A']); // prev maxFreq, and current one which has changed, so has a possibility of being max

            //now , check if valid
            // not valid ->
            // IMP: using if instead of while also works 
            // Thus, T(n) = O(n)
            while (right - left + 1 - maxFreq > k) {
                hash[s[left]-'A']--; // since we will move left by one
                maxFreq = 0;
                for (int i=0;i<26;i++) maxFreq = max(maxFreq, hash[i]); // recalculate maxFreq
                left++;
            } 

            // now, r-l+1-maxFreq <= k => 
            if (right - left + 1 - maxFreq <= k) maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};