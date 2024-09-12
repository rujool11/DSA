// GFG DFS

class Solution {
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int visited[V] = {0};
        int start = 0;
        vector<int> DFS;
        
        DFSHelper(start, adj, visited, DFS);
        return DFS;
    }
    
    private:
        void DFSHelper(int node,vector<int> adj[],
                        int visited[], vector<int>& DFS) {
            
            visited[node] = 1;
            DFS.push_back(node);
            
            for (auto it: adj[node]) {
                if (!visited[it]) {
                    DFSHelper(it, adj, visited, DFS);
                }
            }
        }
};