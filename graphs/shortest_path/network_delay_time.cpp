// Leetcode 743. Network Delay time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        vector<int> distance(n+1, INT_MAX);

        for (auto it: times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        priority_queue<pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>> pq;

        distance[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int dist = it.first;
            int node = it.second;

            for (auto it: adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                if (dist + edgeWt < distance[adjNode]) {
                    distance[adjNode] = dist + edgeWt;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }

        int res = -1;
        for (int i=1; i<=n; i++) {
            if (distance[i] == INT_MAX) return -1;
            res = max(res, distance[i]);
        }

        return res;
    }
};