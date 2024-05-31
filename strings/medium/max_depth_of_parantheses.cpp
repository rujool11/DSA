// 1614. Maximum nesting depth of the parantheses
class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int max = 0;

        for (char x: s){
            if (x=='(') count++;
            else if (x==')') count--;

            if (max<count) max = count;
        }

        return max;
    }
};