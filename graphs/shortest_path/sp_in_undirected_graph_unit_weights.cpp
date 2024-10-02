// GFG Shortest Path in Undirected Graph
// basically dijkstras, but use q instead of pq since unit weights so pq unnecessary

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> adj[N];
        // get adjacency list for undireccted 
        for (auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int distance[N];
        // init distances to infinity
        for (int i=0 ;i<N; i++) distance[i] = INT_MAX;
        
        queue<int> q;
        q.push(src);
        distance[src] = 0; // distance of src should be 0 since starting from src
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto it: adj[node]) {
                if (distance[node] + 1 < distance[it]) {
                    distance[it] = distance[node] + 1;
                    q.push(it);
                }
            }
        }
        
        vector<int> res(N);
        for (int i=0; i<N; i++) {
            if (distance[i] < INT_MAX) res[i] = distance[i];
            else res[i] = -1;
        }
        
        return res;
    }
};
