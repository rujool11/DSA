// Leetcode 14. Longest common prefix
// important learning -> s.compare(x, y, z) -> gives 0 if equal, non zero if unequal
// x - index of s from where comparison starts, y is no. of chars to compare, and z is string to compare to 

class Solution {
public:
    string shortestString(vector<string>& strs){
        int min = INT_MAX;
        string minStr = "";
        for (int i=0;i<strs.size();i++){
            if (strs[i].size()<min) {
                min = strs[i].size();
                minStr = strs[i];
            }
        }

        return minStr;
    }

    bool checkIfValidPrefix(vector<string>& strs, string pref){
        for (string x: strs){
            if (x.compare(0, pref.size(), pref)!=0) return false;
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string min = shortestString(strs); 
        string res = "";

        for (int i=0;i<min.size();i++){
            if (checkIfValidPrefix(strs, min.substr(0,i+1))) {
                res = min.substr(0,i+1);
            }
        }

        return res;
    }
};