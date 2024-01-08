vector<int> printNos(int x) {

    if (x==1){return {1};}
    else{
        vector<int> arr = printNos(x-1);
        arr.push_back(x);
        return arr;
    }
}
