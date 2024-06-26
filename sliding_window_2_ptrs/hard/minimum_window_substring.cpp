//Leetcode 76. mininum window substring

class Solution {
public:

    string minWindow(string s, string t) {
        // every char in t must be included in s
        // to return min substr of s that satisfies this ^
        // imp to note : each char must occur at least as many times as it occurs in t

        unordered_map<char, int> hash;
        for (int i=0;i<256;i++) hash[i] = 0; // init to 0 for all chars

        for (char x : t) hash[x]++; // store freqs of t chars in hash

        int start = -1; // starting index
        int minLen = INT_MAX; // min length of required substring

        int left = 0, right = 0; 
        int count = 0;

        while (right < s.size()) {
            
            // DECREASE in hash when you encounter char
            // in this question, decrease when insertion, increase when removal
            
            if (hash[s[right]] > 0) count++;
            hash[s[right]]--;

            // when count = size of t, all chars have occurred reqd number of times
            while (count == t.size()) { // while to try to shrink as much as possible
                if (minLen > right - left + 1) {
                    minLen = right - left + 1;
                    start = left;
                }

                hash[s[left]]++; // since we are removing it from consideration
                if (hash[s[left]] > 0) count--;
                left++;
            }

            right++;
        }

        return (start == -1) ? "" : s.substr(start, minLen);

    }
};