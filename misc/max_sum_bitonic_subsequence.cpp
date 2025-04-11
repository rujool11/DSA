// given n (length), lo (smallest value in range) and hi(highest value in range)
// construct a bitonic subsequence (strictly increasing at first, then strictly decreasing)
// of length n from [lo, hi] such that its sum is maximized

vector<int> constructBitonic(int n, int lo, int hi) {

    // r -> len of increasing portion
    // s -> len of decreasing portion
    // total length n = r + s - 1 (-1 since peak counted in both)

    // inc -> [hi-r+1, hi-r+2, ..., hi-1, hi]
    // dec -> [hi, hi-1, hi-2, ..., hi-s+1]
    // total -> [hi-r+1, hi-r+2,  ..., hi-1, hi, hi-1, ..., hi-s+1]

    // max sum when both parts as close as possible i.e ideally 
    // since n = (r + s -1) => r + s = n + 1
    // avg = (n+1)/2, r = floor(avg), s = ceil(avg)


    int maxlen = 2*(hi-lo) + 1; // eg [2,5] -> [2,3,4,5,4,3,2] : 2*(5-2) + 1
    if (n < 3 || n > maxlen) return {-1}; // not possible

    // n = r + s -1
    int r = (n+1)/2;
    int s = n + 1 - r;

   if (hi-r+1 < lo || hi-s+1 < lo) return {-1}; // not possible since these are the bounds

   vector<int> inc;
   vector<int> dec;

    for (int i=hi-r+1; i<=hi; i++) {
        inc.push_back(i);
    }

    for (int i=hi-1; i>=hi-s+1; i++) {
        dec.push_back(i);
    }

    vector<int> res;
    for (auto x: inc) res.push_back(x);
    for (auto x: dec) res.push_back(x);

    return res;

}