int floorSqrt(int n)
{
    long long low = 1;
    long long high = n;

    while (low<=high){
        long long mid = low + (high - low)/2;
        long long product = mid*mid;

        if (product <= n){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return high; // low ends up pointing to the first element that 
    //does not satisfy, so high is the largest number satisfying this condition
}
