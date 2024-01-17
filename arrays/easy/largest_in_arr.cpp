#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    int max = arr[0];
    for (auto num: arr){
        if (num>max) {max = num;}
    }
    return max;
}

