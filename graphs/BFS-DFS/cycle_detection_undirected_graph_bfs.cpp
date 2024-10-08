// GFG cycle detection in undirected graph
// using BFS

class Solution {
  private:
    bool detect(int src, vector<int> adj[], int visited[]) {
        visited[src] = 1;
        queue<pair<int,int>> q; // {node, parent}
        q.push({src, -1});
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto adjacentNode: adj[node]) {
                if (!visited[adjacentNode]) {
                    visited[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                
                else if (parent != adjacentNode) {
                    // if visited, and is NOT the parent
                    // means, current node did not come from it, but
                    // node is still visited => cycle
                    
                    return true;            
                }
            }
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // components may not all be connected
        // write for multiple components of graph
        
        int visited[V] = {0};
        bool res = false;
        for (int i=0; i<V; i++) {
            if (!visited[i]) {
                if (detect(i, adj, visited)) return true;
            }
        }
        
        return false;
    }
};