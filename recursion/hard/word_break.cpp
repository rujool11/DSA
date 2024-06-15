// Leetcode 139. Word Break
// time limit exceeded, is a DP problem , backtracking implementation here

class Solution {
public:

    bool inDict(string x, vector<string>& wordDict) {
        for (string s: wordDict){
            if (x == s) return true;
        }
        return false;
    }

    bool doStuff(string s, vector<string>& wordDict, int index) {
        if (index==s.size()) return true;

        for (int i=index; i<s.size(); i++){
            if (inDict(s.substr(index, i-index+1), wordDict) && doStuff(s, wordDict, i+1)) return true;
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return doStuff(s, wordDict, 0);
    }
};