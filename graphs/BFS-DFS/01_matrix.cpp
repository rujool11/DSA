// Leetcode 542. 01 Matrix
// min dist to nearest 0

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // m rows, n cols
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> visited(m, vector<int> (n, 0));
        vector<vector<int>> dists(m, vector<int> (n, 0));

        queue<pair<pair<int,int>, int>> q; // ((row, col) steps/time)

        // start at every cell already a 0, 
        // move BFS (level wise), and mark the distances to all non zero cells

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                // start from cells alreay having 0s, then BFS
                if (mat[i][j] == 0) {  // since nearest cell having 0
                    q.push({{i,j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dists[row][col] = steps;

            for (int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                bool inBounds = (nrow>=0 && ncol>=0 && ncol<n && nrow<m);
                if (inBounds && !visited[nrow][ncol]) {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps+1});
                }
            }
            
        }

        return dists;
    }
};