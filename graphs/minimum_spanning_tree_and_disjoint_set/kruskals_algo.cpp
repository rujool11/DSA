// GFG minimum spanning tree

class DisjointSet {
    vector<int> rank, parent, size;

    public: 
        DisjointSet(int n) {

            rank.resize(n+1, 0);
            size.resize(n+1, 0);
            parent.resize(n+1);

            for (int i=0; i<=n; i++) parent[i] = i;
        }

        int findUParent(int node) {

            if (node == parent[node]) return node;
            // parent[node] = ... since path compression
            // when ultimate parent found, parent is set, thus path compression
            return parent[node] = findUParent(parent[node]); 
        }


        void unionBySize(int u, int v) {
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);

            if (ulp_u == ulp_v) return; // already component

            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            
            // in case of equal case too, just attach, so same function
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};


class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        // Kruskals algo
        vector<pair<int, pair<int,int>>> edges;
        for (int i=0; i<V; i++) {
            for (auto it: adj[i]) {
                int wt = it[1];
                int node = it[0];
                edges.push_back({wt, {i, node}});
            }
        }
        
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int sum = 0;
        
        for (auto it: edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if (ds.findUParent(u) == ds.findUParent(v)) continue;
            
            ds.unionBySize(u, v);
            sum += wt;
        }
        
        return sum;
        
    }
};