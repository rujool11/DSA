// Disjoint set findParent and union by rank and size coding

// n+1 sizing, to work for both 1-based and 0-based indexing

#include <bits/stdc++.h>
using namespace std;

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


        void unionByRank(int u, int v) {
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);

            if (ulp_u == ulp_v) return; // already component

            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }

            else if (rank[ulp_v] < rank[ulp_v]) {
                parent[ulp_v] = ulp_u;
            }

            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_v]++; // increase rank when both have equal ranks
                // when one has lesser rank (as above 2 cases => total rank stays same)
            }

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

void check (DisjointSet ds, int x, int y) {
    if (ds.findUParent(x) == ds.findUParent(y)) cout<<"in same component"<<endl;
    else cout<<"not in same component"<<endl;
}


int main() {
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    
    check(ds, 3, 7);
    ds.unionByRank(3,7);
    check(ds, 3, 7);
    
    DisjointSet ds1(7);
    ds1.unionBySize(1,2);
    ds1.unionBySize(2,3);
    ds1.unionBySize(4,5);
    ds1.unionBySize(6,7);
    ds1.unionBySize(5,6);
    check(ds1, 3, 7);
    ds1.unionBySize(3,7);
    check(ds1, 3, 7);

    return 0;
}