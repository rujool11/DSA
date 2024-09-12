// Leetcode 547. number of provinces

class Solution {
public:
    void bfs(vector<int> adj[], vector<int>& visited, int start) {
        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto it: adj[node]) {
                if (!visited[it]) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);

        vector<int> adjList[n];
        // get adjList
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (isConnected[i][j] && i!=j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                } 
            }
        }

        // no. of provinces = no. of starting points
        int count = 0;
        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                count++;
                bfs(adjList, visited, i);
            }
        }

        return count;
    }
};