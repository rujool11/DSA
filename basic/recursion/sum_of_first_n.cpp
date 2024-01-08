long long sumFirstN(long long n) {
    if (n == 1) {return 1;}
    else{
        long long ans = sumFirstN(n-1)+n;
        return ans;
    }
}
