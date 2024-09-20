// Leetcode 1020. number of enclaves

class Solution {

public:
    int numEnclaves(vector<vector<int>>& grid) {
        // land region does not have boundary => cannot walk off
        // find regions without boundary
        // total regions - regions with boundary

        // mark and find boundary regions, 
        // and then find cells that are 1 but not visited


        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int,int>> q;


        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, -1, 0, 1};

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i==0 || j==0 || i==m-1 || j==n-1 ) { // boundary
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i=0 ;i<4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                bool inBounds = (nrow>=0 && ncol>=0 && nrow<m && ncol<n);

                if (inBounds && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }

        }

        int count = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) count++;
            } 
        }

        return count;

    }
};