// Leetcode 151. Reverse words in a string
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string res = "";
        int start = 0;
        int len = 0;


        for (int i=0;i<=s.size();i++){
            if (s[i]==' ' || i==s.size()){
                if (len!=0){
                    words.push_back(s.substr(start,len));}
                len = 0;
                start = i+1;
            }
            else {
                len++;
            }
        }
        

        for (int i=words.size()-1; i>=0; i--){
            res += words[i];
            if (i!=0) res+= " ";
        }


        return res;
    }
};