// GFG perfect sum : count all subsets with value equal to given sun
// ideally dp solution, but recursive backtracking used here

class Solution{

	public:
	const int MOD = 100000007; // question constraints
	
	void doStuff(vector<vector<int>>& ans, vector<int>& helper, int& vs, int index, int n, int sum, int arr[]){
	    // vs is the variable sum
	    if (index==n){
	        if (vs==sum){
	            ans.push_back(helper);
	        }
	        return;
	    }
	    
	    helper.push_back(arr[index]);
	    vs += arr[index];
	    doStuff(ans, helper, vs, index+1, n, sum, arr);
	    
	    helper.pop_back();
	    vs -= arr[index];
	    doStuff(ans, helper, vs, index+1, n, sum , arr);
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> ans;
        vector<int> helper;
        int vs = 0;
        doStuff(ans, helper, vs, 0, n, sum, arr);
        return ans.size() %  MOD;
	}
	  
};
