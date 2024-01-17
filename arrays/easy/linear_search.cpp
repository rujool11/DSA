int linearSearch(int n, int num, vector<int> &arr)
{
    int res = -1;
    for (int i=0;i<n;i++){
        if (arr[i]==num) {res = i;break;}
    }

    return res;
}
