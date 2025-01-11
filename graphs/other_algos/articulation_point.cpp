// GFG articulation point I 

class Solution {
  public:
    void dfs(int node, int parent, vector<int>& visited, 
            vector<int>& tin, vector<int>& low, vector<int>& mark,
            vector<int> adj[], int timer) {

            visited[node] = 1;
            tin[node] = low[node] = timer;
            timer++;
            int child = 0;

            for (auto adjNode: adj[node]) {
                if (adjNode == parent) continue;

                if (!visited[adjNode]) {
                    dfs(adjNode, node, visited, tin, low,mark,adj, timer);
                    low[node] = min(low[node], low[adjNode]); // take lowest from child

                 
                    if (low[adjNode] >= tin[node] && parent!=-1) { // articulation point condition
                        mark[node] = 1;
                    }
                    child++;
                }
                else {
                    low[node] = min(low[node], tin[adjNode]); // modified for this
                }
            }
            
            if (child > 1 && parent == -1) { // if starting node and multiple children, 
            //then definitely articulation point
                mark[node] = 1;
            }
            
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // tarjans algorithm
        // but , low array -> min of all adj nodes apart from 
        // parent AND VISITED NODES
        vector<int> visited(V, 0);
        vector<int> tin(V);
        vector<int> low(V);
        
        vector<int> mark(V, 0);
        int timer = 1;
        for (int i=0; i<V; i++) {
            if (!visited[i]) dfs(i, -1, visited, tin, low, mark, adj, timer);
        }
        
        vector<int> ans;
        for (int i=0; i<V; i++) {
            if (mark[i] == 1) ans.push_back(i);
        }
        
        if (ans.size() == 0) return {-1};
        return ans;
    }
};