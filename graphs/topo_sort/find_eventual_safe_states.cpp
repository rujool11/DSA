// Leetcode 802. find eventual safe states
// BFS solution / Kahns algo 


// reverse graph edges => topo sort gives safe states

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> reverseGraph[V];
        vector<int> indegree(V, 0);

        for (int i=0; i<V; i++) {
            for (auto it: graph[i]) {
                reverseGraph[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeStates;

        for (int i=0; i<V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safeStates.push_back(node);

            for (auto it: reverseGraph[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }

        }

        sort(safeStates.begin(), safeStates.end());
        return safeStates;
    }
};