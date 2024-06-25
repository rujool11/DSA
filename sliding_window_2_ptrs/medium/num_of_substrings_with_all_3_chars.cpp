// Leetcode 1358. number of substrings containing all 3 characters

class Solution {
public:

    int mmin(int a, int b, int c) {
        if (a < b) {
            if (a < c) return a;
            return c;
        }

        if (b < c) return b;
        return c;
    }

    int numberOfSubstrings(string s) {
        unordered_map<char, int> lastSeen;
        // -1 signifies that char hasnt been seen yet
        lastSeen['a'] = -1;
        lastSeen['b'] = -1;
        lastSeen['c'] = -1;

        int count = 0;

        for (int i=0; i<s.size(); i++) {
            lastSeen[s[i]] = i; // curr char most recently seen at curr index
            
            bool check = (lastSeen['a']!=-1) && (lastSeen['b']!=-1) && (lastSeen['b']!=-1);
            if (check) {
                count += (1 + mmin(lastSeen['a'], lastSeen['b'], lastSeen['c']));
            }
        }

        return count;
        
    }
};