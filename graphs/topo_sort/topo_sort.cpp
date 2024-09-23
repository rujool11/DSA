// GFG Topological Sort
// Topo sort using DFS

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int node, stack<int>& st, int visited[], vector<int> adj[]) {
	    
	    visited[node] = 1;
	    
	    for (auto it: adj[node]) {
	        if (!visited[it]) dfs(it, st, visited, adj);
	    }
	    
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int> res;
        int visited[V] = {0};
        stack<int> st;
        
        for (int i=0; i<V; i++) {
            if (!visited[i]) dfs(i, st, visited, adj);
        }
        
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
	}
};