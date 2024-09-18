// Leetcode 994. Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // an orange rots neighbouring oranges => BFS/ level wise
        // starting points => initial rotten oranges

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0)); 
        // 1 if visited, 2 if rotten

        queue<pair<pair<int,int>, int>> q; // {(row, col), time}
        int fresh = 0;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else if (grid[i][j] == 1)fresh++;
            }
        }

        int time = 0;
        int count = 0;
        // to traverse neighbours
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};


        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            // since 4 neighbours: top, down, left, right
            for (int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                // check if in bounds and not rotten, and fresh orange exists
                if (nrow>=0 && nrow<rows && ncol>=0 && ncol<cols
                    && visited[nrow][ncol]!=2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t+1});
                    visited[nrow][ncol] = 2;
                    count++;
                }
            }
        }

        if (count != fresh) return -1;
        return time;
    }
};