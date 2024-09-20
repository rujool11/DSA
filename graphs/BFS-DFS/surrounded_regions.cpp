// Leetcode 130. Surrounded regions
// REMEMBER -> 'O' used , and not '0'
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& board) {
        visited[row][col] = 1;
        int m = board.size();
        int n = board[0].size();

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            bool inBounds = (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n);

            if (inBounds && !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, visited, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) { // first and last row
            if (!visited[0][i] && board[0][i] == 'O') { // first row
                dfs(0, i, visited, board);
            }
            if (!visited[m - 1][i] && board[m - 1][i] == 'O') { // last row
                dfs(m - 1, i, visited, board);
            }
        }

        for (int i = 0; i < m; i++) { // first and last column
            if (!visited[i][0] && board[i][0] == 'O') { // first column
                dfs(i, 0, visited, board);
            }
            if (!visited[i][n - 1] && board[i][n - 1] == 'O') { // last column
                dfs(i, n - 1, visited, board);
            }
        }

        // Converting surrounded regions to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
