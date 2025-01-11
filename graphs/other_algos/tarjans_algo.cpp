// Leetcode 1192. critical connections in a network
// also known as Bridges in a graph
// Tarjans Algorithm

class Solution {
public:
    void dfs(int node, int parent, vector<int>& visited, 
            vector<vector<int>>& adj, vector<int>& tin, vector<int>& low,
            vector<vector<int>>& bridges, int timer) {

            visited[node] = 1;
            tin[node] = low[node] = timer;
            timer++;

            for (auto adjNode: adj[node]) {
                if (adjNode == parent) continue;

                if (visited[adjNode] == 0) {
                    dfs(adjNode, node, visited, adj, tin, low,bridges, timer);
                    low[node] = min(low[node], low[adjNode]); // take lowest from child

                    // node -- adjNode can be bridge? ->
                    if (low[adjNode] > tin[node]) { // condition for being a bridge
                        bridges.push_back({adjNode, node});
                    }
                }
                else {
                    low[node] = min(low[node], low[adjNode]);
                }
            }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Tarjans algorithm
        // time (time of insertion) and low (lowest time of insertion apart from parent) arrays
        // to keep track of time of insertion in DFS, etc

        vector<vector<int>> adj(n);

        for (auto it: connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n, 0);
        vector<int> tin(n), low(n); // time-of-in and low
        vector<vector<int>> bridges;
        int timer = 1;
        dfs(0, -1, visited, adj, tin, low, bridges, timer);
        return bridges;
    }
};