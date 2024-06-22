// number of nge GFG
class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        
        vector<int> ans(queries);
        for (int i=0; i<queries; i++){
            int curr = arr[indices[i]];
            stack<int> s;
            
            for (int j=n-1; j>=indices[i]; j--) {
                if (arr[j] > curr) s.push(arr[j]);
            }
            ans[i] = s.size();
        }
        return ans;
       
    }

};