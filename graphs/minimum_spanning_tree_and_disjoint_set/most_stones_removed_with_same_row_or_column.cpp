// 947. Most stones removed with same row or column

class DisjointSet {
    public: 
    vector<int> size, parent;
    DisjointSet(int n) {

        size.resize(n+1, 0);
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
            size[up_v] += size[up_v];
        }

    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // think of connected stones as graph components
        // each component ci has xi stones => x1 + x2 + ... = n (total stones)
        // in each component, can remove every stone aside from one => xi - 1
        // => total stones removed = (x1-1) + (x2-1) + ... = n - (conn_comps)
        // ans = (n - num_of_connected_components)

        int maxRow = 0;
        int maxCol = 0;
        for (auto it: stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> unique_nodes;

        for (auto it: stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1; // data structured so that col is after row
            ds.union_s(nodeRow, nodeCol);

            unique_nodes[nodeRow] = 1;
            unique_nodes[nodeCol] = 1;
        }

        int count = 0;
        for (auto it: unique_nodes) {
            // find number of components
            if (ds.find(it.first) == it.first) count++;

        }

        return stones.size() - count;
    }
};