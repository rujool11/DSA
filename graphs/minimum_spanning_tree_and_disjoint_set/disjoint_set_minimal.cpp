// minimal disjoint set class, for use in questions
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public: 
    vector<int> size, parent;
    DisjointSet(int n) {

        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i=0; i<=n; i++) parent[i] = i;
        
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
            size[up_u] += size[up_v];
        }

    }
};