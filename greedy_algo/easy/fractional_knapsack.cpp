// GFG fractional knapsack

/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        
        double ans = 0.0;
        double currWeight = 0;
        // sort items w.r.t value per weight
        sort(arr, arr+n ,[](Item& a, Item& b) {
            double A = (double)a.value / (double)a.weight;
            double B = (double)b.value / (double)b.weight;
            return A > B;
        } );
        
        for (int i=0; i<n; i++) {
            if (currWeight + arr[i].weight > w) {
                int remaining = w - currWeight;
                ans += ((double)arr[i].value)/((double)arr[i].weight)*remaining;
                break;
            }
            
            else{
               currWeight += arr[i].weight;
               ans += arr[i].value;
            }
            
        }
        return ans;
    }
};