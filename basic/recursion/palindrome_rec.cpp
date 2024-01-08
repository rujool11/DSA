bool isPalindrome(string& str) {
    if (str.length()==1) {return true;}
    if (str.length()==2 && str[0]==str[1]) {return true;}

    else if (str[0]!=str.back()){return false;}
    else {
        string temp_str =  str.substr(1,str.length()-2);
        return isPalindrome(temp_str);
    }
}

