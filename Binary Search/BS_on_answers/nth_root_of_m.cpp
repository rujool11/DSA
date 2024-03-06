// Coding ninjas Nth root of M
// CHECK SOLUTION, not working fully
int f(int n, int mid,int m){ 
  /*
  return 0 is < m
  1 if == m
  2 if > m, to avoid overflow conditions in case of big numbers
  */

  long long ans = 1;

  for (int i=1;i<=n;i++){
    ans *= mid;
    if (ans>m) return 2;
  }

  if (ans==m) return 1;
  return 0;

}

int NthRoot(int n, int m) {
  int low = 1;
  int high = n;

  while (low<=high){
    int mid = low + (high-low)/2;
    if ( f(n,mid,m) == 1) return mid;

    else if (f(n,mid,m) == 0) low = mid + 1;

    else high = mid - 1;
  }

  return -1;
}