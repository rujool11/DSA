// Leetcode 20. Valid Parantheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        

        for (char x: s) {
            
            switch(x) {
                case ')': (!st.empty() && st.top()=='(') ? st.pop() : st.push(x); break;
                case ']': (!st.empty() && st.top()=='[') ? st.pop() : st.push(x); break;
                case '}': (!st.empty() && st.top()=='{') ? st.pop() : st.push(x); break;
                default: st.push(x); break;
            }
        }

        return st.empty();
    }
};