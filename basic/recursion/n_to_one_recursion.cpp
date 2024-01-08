vector<int> printNos(int x) {
    if (x==1) {return {1};}
    else{
        vector<int> ans = printNos(x-1);
        ans.insert(ans.begin(),x);
        return ans;
    }
}
