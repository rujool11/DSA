// GFG shorted path in directed acyclic graph

class Solution {
  private:
     void topoSort(int i, vector<pair<int,int>> adj[], int visited[], stack<int>& st) {
        visited[i] = 1;
        
        for (auto it: adj[i]) {
            int node = it.first;
            if (!visited[node]) topoSort(node, adj, visited, st);
        }
        
        st.push(i);
    }
     
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        int src = 0; // since src always 0 for this problem
        vector<pair<int,int>> adj[N];
        
        for (int i=0; i<M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        // get topo sort
        int visited[N] = {0};
        stack<int> topo;
        for (int i=0; i<N; i++) {
            if (!visited[i]) topoSort(i, adj, visited, topo);
        }
        
        // distance relaxation etc.        
        vector<int> dist(N, INT_MAX);
        dist[src] = 0; // set src dist to 0
        while (!topo.empty()) {
            int node = topo.top();
            topo.pop();
            
            for (auto it: adj[node]) {
                int v = it.first;
                int wt = it.second;
                
                // relaxation
                // (dist[node] != INT_MAX has to be checked in case of overflow leading to negative values)
                if (dist[node] != INT_MAX && dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        vector<int> res(N);
        for (int i=0; i<N; i++) {
            if (dist[i] == INT_MAX) res[i] = -1;
            else res[i] = dist[i];
        }
        return res;
    }
};
