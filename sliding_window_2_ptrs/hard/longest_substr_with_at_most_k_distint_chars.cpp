// Naukri.com (coding ninjas 360 ) longest substring with at most k distinct chars
// same as fruits in basket, except generalized for k 


int kDistinctChars(int k, string &str) {

  unordered_map<char, int> hash;
  int left = 0, right = 0;
  int maxLen = 0;

  while (right < str.size()) {

      hash[str[right]]++;

      while (hash.size() > k) {
          hash[str[left]]--;
          if (hash[str[left]] == 0) hash.erase(str[left]);
          left++;
      }

      maxLen = max(maxLen, right - left + 1);

      right++;
  }
  
  return maxLen;
}