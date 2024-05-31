// Leetcode 1781. sum of beauty of all substring
// revise
class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        int n = s.length();
    
        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0); // frequency of characters
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++; // update frequency of characters
                int maxFreq = 0, minFreq = n;
                for (int k = 0; k < 26; ++k) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }
                totalBeauty += (maxFreq - minFreq); // add beauty of current substring
            }
        }
    
        return totalBeauty;
    }
};