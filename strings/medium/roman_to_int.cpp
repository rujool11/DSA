// Leetcode 13. Roman to Integer
class Solution {
public:
    int romanToInt(string s) {
        map<char,pair<int,int>> lookup = {
            {'I', make_pair(1,1)},
            {'V', make_pair(5,2)},
            {'X', make_pair(10,3)},
            {'L', make_pair(50,4)},
            {'C', make_pair(100,5)},
            {'D', make_pair(500,6)},
            {'M', make_pair(1000,7)}
        };

        ;

        int res = 0;
        for (int i=0;i<s.size();i++){
            res += lookup[s[i]].first;
            if (i!=0 && lookup[s[i]].second>lookup[s[i-1]].second){
                res -=  2*lookup[s[i-1]].first;
            }
        }

        return res;
    }
};