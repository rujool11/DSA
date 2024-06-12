// Leetcode 17. Letter combinations of phone number
class Solution {
public:

    void doStuff(vector<string>& ans, string& helper, vector<string>& letters,string digits,int index){
        if (index==digits.size()){
            ans.push_back(helper);
            return;
        }

        string s = letters[digits[index]-'0'];
            
        for (char x: s){
            helper += x;
            doStuff(ans, helper, letters, digits, index+1);
            helper.pop_back();
        }
        
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits==""|| digits==" ") {
            return ans;
        }
        string helper = "";
        vector<string> letters = {"", "",
            "abc", "def", "ghi", "jkl", "mno",
             "pqrs", "tuv", "wxyz"}; 
        doStuff(ans, helper, letters,digits, 0);
        return ans;
    }
};