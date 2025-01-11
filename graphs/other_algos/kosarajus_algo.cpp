// GFG number of strongly connected components in a graph

class Solution {
  public:
    void dfs(int x, vector<int>& vis,
                vector<vector<int>>& adj, stack<int>& st) {
        
        vis[x] = 1;
        for (auto it: adj[x]) {
            if (!vis[it]) dfs(it, vis, adj, st);
        }
        
        st.push(x);
    }
                
    int kosaraju(vector<vector<int>> &adj) {
        
        int V = adj.size();
        vector<int> vis(V, 0);
        stack<int> st;
        
        // sort according to finishing times
        for (int i=0; i<V; i++) {
            if (!vis[i]) dfs(i, vis, adj, st);
        }
        
        // reverse edges
        vector<vector<int>> revAdj(V);
        for (int i=0; i<V; i++) {
            vis[i] = 0; // mark unvisited for next DFS
            for (auto it: adj[i]) {
                revAdj[it].push_back(i);
            }
        }
        
        // DFS to find components
        stack<int> s; // just used to fit function template, basically useless
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            if (!vis[node]) {
                dfs(node, vis, revAdj, s);
                scc++;
            }
         }
         
         return scc;
        
    }
};