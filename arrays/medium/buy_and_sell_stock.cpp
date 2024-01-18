class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int maxProfit = 0;
        for (int i=1;i<prices.size();i++){
            int profit = prices[i] - minimum;
            if (profit>maxProfit) {maxProfit=profit;}
            minimum = min(minimum, prices[i]);
        }

        return maxProfit;
    }
};
