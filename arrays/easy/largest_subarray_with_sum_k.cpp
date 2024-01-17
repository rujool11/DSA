#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& a, int k){
    long long sum = 0;
    int maxLen = 0;
    unordered_map<int,int> preMap;
    //map stores prefix sum at an index i , {presum: index}
    for (int i=0;i<a.size();i++){
        sum += a[i];

        if (sum==k){
            maxLen = max(maxLen,i+1);
        }

        int rem = sum-k;
        if (preMap.find(rem)!=preMap.end()){
            int len = i - preMap[rem];
            maxLen = max(maxLen,len);
        }

        if (preMap.find(sum)==preMap.end()){
            preMap[sum] = i;
        }
    }

    return maxLen;
    
}
