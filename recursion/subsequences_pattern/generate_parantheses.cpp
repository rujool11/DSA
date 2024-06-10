// Leetcode 22. Generate Parantheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, n, "", result);
        return result;
    }

    void generate(int open, int close, string current, vector<string>& result) {
        // both open ans close 0 => valid combo formed, thus push in result
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }
        
        if (open > 0) {
            generate(open - 1, close, current + "(", result);
        }
        
        if (close > open) {
            generate(open, close - 1, current + ")", result);
        }
    }
};
