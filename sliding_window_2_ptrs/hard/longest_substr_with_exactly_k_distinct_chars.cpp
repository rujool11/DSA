// GFG longest subtr with exactly k distinct chars
// similar to longest .. at most k distinct, but add a hash_size == k before updating longest

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int> hash;
        int left = 0, right = 0;
        int maxLen = -1;
        
        while (right < s.size()) {
            hash[s[right]]++;
            
            while (hash.size() > k) {
                hash[s[left]]--;
                if (hash[s[left]] == 0) hash.erase(s[left]);
                left++;
            }
            
            if (hash.size() == k) maxLen = max(maxLen, right - left + 1);
            right++;
        }
        
        return maxLen;
    }

};