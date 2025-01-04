// GFG number of ways to arrive at a destination

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // to find number of shortest paths
        vector<pair<int, long long>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, 
                       greater<>> pq;
        
        vector<long long> distance(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        
        distance[0] = 0;
        ways[0] = 1; // only one way to start
        pq.push({0, 0});
        int mod = (int)(1e9 + 7);
        
        while (!pq.empty()) {
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto it : adj[node]) {
                int adjNode = it.first;
                long long edgeWt = it.second;
                
                // first time with this distance
                if (dist + edgeWt < distance[adjNode]) {
                    distance[adjNode] = dist + edgeWt;
                    pq.push({distance[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                
                else if (dist + edgeWt == distance[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod; // found other way
                }
            }
        }
        
        return ways[n - 1] % mod;
    }
};