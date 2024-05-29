// Leetcode 1021. Remove outermost parantheses
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int count = 0;
        // count keeps track of opened parantheses
        for (char c: s){
            if (c=='(' && count++>0 ){
                result += c;
            }
            if (c==')' && count-->1 ){
                result += c;
            }
        }

       return result;
    }
};