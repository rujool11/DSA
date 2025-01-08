// GFG minimum spanning tree

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        // only to find sum => no need to store parents
        // (weight, node)
        priority_queue<pair<int,int>, 
                vector<pair<int,int>>, greater<pair<int,int>>> PQ: // mn heap
                
        vector<int> visited(V, 0);
        
        PQ.push({0, 0});
        int sum = 0;
        
        while (!PQ.empty()) {
            auto it = PQ.top();
            PQ.pop();
            
            int node = it.second;
            int wt = it.first;
            
            if (visited[node] == 1) continue; // already visited => skip
            visited[node] = 1; // mark visited
            sum += wt; // update sum
            
            for (auto it: adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];
                
                if (!visited[adjNode]) {
                    PQ.push({edgeWt, adjNode});
                }
            }
        }
        
        return sum;
    }
};