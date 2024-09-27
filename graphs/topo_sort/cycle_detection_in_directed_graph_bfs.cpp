// cycle detection in directed graph using BFS (prev done using DFS)

// if toposort has exactly V elements => DAG
// if < V elements => cycle

class Solution {
  public:
    // if toposort has V elements exactly, DAG
    // if toposort has < V elements, cycle 
    
    bool isCyclic(int V, vector<int> adj[]) {
        int indegree[V] = {0};
        for (int i=0; i<V; i++) {
            for (auto it: adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for (int i=0; i<V; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> res;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for (auto it: adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        
        return (res.size() < V);
    }
};