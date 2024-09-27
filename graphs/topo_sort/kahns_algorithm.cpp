// GFG Topological sort
// Basically Topo Sort using BFS

class Solution
{
	public:
	//Kahns Algo
	// at each step, add node with indegree 0 in queue
	// T(n) = O(V+E)
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> res;
	    
        int indegree[V] =  {0};
        
        for (int i=0; i<V; i++) {
            for (auto it: adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for (int i=0; i<V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            res.push_back(node);
            // node is in topo sort, so remove from indegree
            
            for (auto it: adj[node]) {
                indegree[it]--; //node is now removed from its adj's indegree
                if (indegree[it] == 0) q.push(it);
                // if indegree 0, push it to q
                
            }
            
        }
        
        return res;
    }
};