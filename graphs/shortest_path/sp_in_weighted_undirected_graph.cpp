// GFG shortest path in weighted undirected graph ( using Dikjstra's algo and parents)

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
       vector<pair<int,int>> adj[n+1];
       for (auto it: edges) {
           int u = it[0];
           int v = it[1];
           int wt = it[2];
           
           adj[u].push_back({v, wt});
           adj[v].push_back({u, wt});
           
       }
       
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       vector<int> distance(n+1, INT_MAX), parent(n+1);
       for (int i=1; i<=n; i++) parent[i] = i;
       distance[1] = 0; // set dist of src to 0
       pq.push({0, 1}); // insert in pq
       
       while (!pq.empty()) {
           auto it = pq.top();
           int node = it.second;
           int dist = it.first;
           pq.pop();
           
           for (auto it: adj[node]) {
               int adjNode = it.first;
               int edgeWt = it.second;
               
               if (dist + edgeWt < distance[adjNode]) {
                   distance[adjNode] = dist + edgeWt;
                   parent[adjNode] = node; // store parents
                   pq.push({distance[adjNode], adjNode});
               }
           }

       }
       
       if (distance[n] == INT_MAX) return {-1};
       vector<int> path;
       int node = n;
       
       while (parent[node] != node) { // parent is node itself => src
           path.push_back(node);
           node = parent[node];
       }
       
       path.push_back(1); // start
       reverse(path.begin(), path.end());
       path.insert(path.begin(), distance[n]); // added cause this is how the code is evaluated
       return path;
       
    }
};
