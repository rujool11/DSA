// GFG cycle detection in directed graph

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<int> adj[], 
            int visited[], int pathVisited[]) {
                
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for (auto it: adj[node]) {
            if (!visited[it]) {
                if (dfs(it, adj, visited, pathVisited)) return true;
            }
            
            // visited in same path, so cycle exists
            else if (pathVisited[it]) return true;
            
        }
        
        pathVisited[node] = 0; // when you go back, remove from path 
        return false;
                
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        int visited[V] = {0};
        int pathVisited[V] = {0};
        
        for (int i=0; i<V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, pathVisited)) return true;
            }
        }
        
        return false;
    }
};