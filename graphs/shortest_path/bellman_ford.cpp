// GFG Bellman-Ford

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        
        // V - 1 iterations (n-1)
        for (int i=0; i<V-1; i++) {
            // relax all edges
            for (auto it: edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                // check if u is reached, and relax
                if (dist[u]!=1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
          
          
        // Nth relaxation to check -ve weight cycle
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            // return {-1} is -ve wt cycle
            if (dist[u]!=1e8 && dist[u] + wt < dist[v]) return {-1};
        }
        
        return dist;
        
    }
};
