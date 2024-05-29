//Leetcode 1903. largest odd number in string
class Solution {
public:

    bool isOdd(char x){
        if (x=='1'||x=='3'||x=='5'||x=='7'||x=='9') return true;
        return false;
    }

    string largestOddNumber(string num) {
        string res = "";
        for (int i=num.size()-1;i>=0;i--){
            if (isOdd(num[i])) {
                res = num.substr(0,i+1); 
                return res;
            }
        }

        return "";
    }
};