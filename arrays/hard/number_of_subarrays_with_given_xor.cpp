#include <unordered_map>
int subarraysWithSumK(vector < int > a, int b) {
    unordered_map<int,int> hash;
    int xsum = 0;
    int count = 0;
    hash[0] = 1; // 0 has already occured


    for (int i=0;i<a.size();i++){
      xsum ^= a[i];
      int rem = xsum^b; //rem since inverse of xor is xor itself
      count += hash[rem]; // all occurences of rem added
      hash[xsum]++; //prefix added
    }

    return count;
}

// look up largest_subarray_with_sum_k