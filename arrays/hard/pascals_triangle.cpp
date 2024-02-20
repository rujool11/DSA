class Solution {
public:

    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> res;
        res.push_back(1);
        for (int col=1;col<row;col++){
            ans = ans*(row-col);
            ans=ans/(col);
            res.push_back(ans);
        }

        return res;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        for (int i=0;i<n;i++){
            res.push_back(generateRow(i+1));
        }

        return res;
    }
};
