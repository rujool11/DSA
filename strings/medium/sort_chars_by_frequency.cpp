// Leetcode 451. sort characters by frequency
class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        map<char,int> m;

        for (char x: s){
            m[x]++;
        }

        // now map has all chars and corresponding frequencies
        // extract the map to a vector of pairs and sort 
        vector<pair<char,int>> v(m.begin(), m.end());

        // sort using custom comparator, can also use a function for 
        // comparison, but we have used lambda function
        sort(v.begin(), v.end(),
        [](const pair<char,int>& a, const pair<char,int>& b){
            return a.second > b.second;
        });

        // for (auto it: v){
        //     for (int i=0;i<it.second;i++) res += it.first;
        // }
        // this can be further optimized

        res.reserve(s.size());
        for (auto it: v){
            res.append(it.second, it.first); // append v.second occurrences of v.first
        }

        return res;
    }
};