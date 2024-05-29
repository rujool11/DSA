// Leetcode 242. Valid anagram
class Solution {
public:
    bool isAnagram(string s, string t) {
        // can also do hashmap solution, but here we count frequencies and check if all 0 by the end
        if (s.size()!=t.size()) return false;

        int freq[26] = {0};

        for (int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }

        for (int i=0;i<26;i++){
            if (freq[i]!=0) return false;
        }
       
       return true;
    }
};