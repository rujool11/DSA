// Adjacency List
// Space = O(V^2)

class Solution {
  public:
    // Function to return the adjacency matrix of a graph
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        int E = edges.size();

        // for 0 - indexed graph. for 1-indexed, V+1 * V+1 
        vector<vector<int>> graph(V, vector<int>(V, 0));
        int u=0, v=0;
        
        for (int i=0; i<E; i++) {
            u = edges[i].first;
            v = edges[i].second;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        
        return graph;
    }
};