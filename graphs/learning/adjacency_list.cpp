// GFG adjacency list
// Space = O(2E), since each edge => 2 nodes => stored twice

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        int E = edges.size();
        
        int u=0, v=0;
        vector<vector<int>> adjList(V);
        
        for (int i=0; i<E; i++) {
            u = edges[i].first;
            v = edges[i].second;
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        return adjList;
    }
};
