// GFG cheapest flights within K stops
// stops is the main thing we have to take care of, not cost, so use q (based on stops/levels)
// instead of pq

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>> adj[n];
        
        for (auto it: flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v, wt});
        }
        
        // first priority is stops, so dont implement PQ
        // go by q, so can go level wise according to number of stops
        
        queue<pair<int,pair<int,int>>> q; // { stops, {node, dist}}
        vector<int> distance(n, INT_MAX);
        q.push({0, {src, 0}});
        distance[src] = 0;
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if (stops > K) continue; // no need go go further in that path
            
            for (auto it: adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;
                
                if (cost + edgeWt < distance[adjNode] && stops<=K) {
                    distance[adjNode] = cost + edgeWt;
                    q.push({stops+1, {adjNode, distance[adjNode]}});
                }
            }
        }
        
        if (distance[dst] == INT_MAX) return -1;
        return distance[dst];
    }
};