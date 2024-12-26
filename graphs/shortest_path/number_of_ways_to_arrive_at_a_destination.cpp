// GFG number of ways to arrive at a destination

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Create adjacency list
        vector<pair<int, int>> adj[n];
        for (auto it : roads) {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
        }
        
        // Min-heap for Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Distance and ways arrays
        vector<int> dist(n, INT_MAX), ways(n, 0);
        dist[0] = 0; // Distance to the source is 0
        ways[0] = 1; // There's only one way to reach the source
        int mod = 1e9 + 7;
        
        pq.push({0, 0}); // {distance, node}
        
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Skip outdated states
            if (dis > dist[node]) continue;
            
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;
                
                // Found a shorter path
                if (dis + edgeWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node]; // Inherit ways from the current node
                }
                
                // Found an equally short path
                else if (dis + edgeWt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        
        return ways[n - 1] % mod;
    }
};
