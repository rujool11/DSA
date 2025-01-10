// Leetcode 1319. number of operations to make network connected

class DisjointSet {
    public: 
    vector<int> size, parent;
    DisjointSet(int n) {

        size.resize(n+1, 0);
        parent.resize(n+1);
        for (int i=0; i<n; i++) parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void union_s(int u, int v) {
        int up_u = find(u);
        int up_v = find(v);

        if (up_u == up_v) return;

        if (size[up_u] < size[up_v]) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }

        else {
            parent[up_v] = up_u;
            size[up_v] += size[up_v];
        }

    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // if nc connected components, => nc-1 edges needed
        // dynamic connections => disjoint set

        // find number of ultimate parents(nc), and check is nc-1 extra edges exist

        DisjointSet ds(n);
        int extra_edges = 0;
        
        for (auto it: connections) {
            int u = it[0];
            int v = it[1];

            if (ds.find(u) == ds.find(v)) extra_edges++; // since already connected
            else {
                ds.union_s(u, v);
            }
        }

        int connected_components = 0;
        for (int i=0; i<n; i++) {
            if (ds.parent[i] == i) connected_components++;
        }

        if (extra_edges >= connected_components-1) return connected_components-1;
        return -1;

    }
};