// Leetcode 131. Palindrome partitioning

class Solution {
public:

    bool isPalindrome(string s){
        int l = 0;
        int r = s.length()-1;

        while (l<=r){
            if (s[l]!=s[r]) return false;
            l++;
            r--;
        }

        return true;
    }

    void doStuff(vector<vector<string>>& ans, vector<string>& helper, string s, int index){

        if (index==s.size()){
            int flag = 0;
            for (string x: helper){
                if (!isPalindrome(x)) flag = 1;
            }
            if (!flag) ans.push_back(helper);
            return;
        }

        for (int i=index; i<s.size(); i++){
            helper.push_back(s.substr(index, i-index+1));
            doStuff(ans, helper, s, i+1);
            helper.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> helper;
        doStuff(ans, helper, s, 0);
        return ans;
    }
};