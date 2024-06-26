// Leetcode 904. Fruit into basket

// can also scale to any number of baskets, just replace 2 with k

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // basically, longest subarray which has at most 2 different numbers
        // Brute force -> all subarrays by two for loops, and keep a set to check 
        // how many distinct no.s if set size > 2 break, else update max 
        // even though adding in set takes logN time, set is of at most 3 elements, so 
        // O(N2) , and space will be O(1) for same reason

        unordered_map<int,int> hash;
        int maxLen = 0;

        int left = 0, right = 0;

        while (right < fruits.size()) {
            hash[fruits[right]]++;

            if (hash.size() > 2) {
                while (hash.size() > 2) {
                    hash[fruits[left]]--;
                    if (hash[fruits[left]] == 0) hash.erase(fruits[left]);
                    // erase used to delete key from map, not just make value 0
                    left++;
                }
            }

            maxLen = max(maxLen, right - left + 1);

            right++;
        }

        return maxLen;
   
    }
};

// while loop used inside if (hash.size() > 2) because the extra fruit might not 
// be at the left index, it may be anywhere inside the window, so trim window such
// that it is removed