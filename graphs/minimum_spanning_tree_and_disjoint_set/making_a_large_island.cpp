// Leetcode 827. Making a large island

class DisjointSet {
public: 
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n+1, 1);  // Initialize with 1
        parent.resize(n+1);
        for (int i = 0; i <= n; i++) 
            parent[i] = i;
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

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        // Find connected components
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                
                int delRow[4] = {-1, 0, 1, 0};
                int delCol[4] = {0, -1, 0, 1};

                for (int i = 0; i < 4; i++) {
                    int nr = row + delRow[i];
                    int nc = col + delCol[i];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1) {
                        int node = row*n + col;
                        int adjNode = nr*n + nc;
                        ds.union_s(node, adjNode);
                    }
                }
            }
        }

        int maxSize = 0;

        // Try changing 0s to 1s
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;

                set<int> components;
                int delRow[4] = {-1, 0, 1, 0};
                int delCol[4] = {0, -1, 0, 1};

                for (int i = 0; i < 4; i++) {
                    int nr = row + delRow[i];
                    int nc = col + delCol[i];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1) {
                        components.insert(ds.find(nr*n + nc));
                    }
                }

                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                maxSize = max(maxSize, sizeTotal + 1); // 1 is the changed component
            }
        }

        return maxSize == 0 ? n*n : maxSize;  // Handle all 1s case
    }
};