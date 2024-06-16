// Leetcode 51. N queens

class Solution
{
public:
    bool isSafe(int row, int col, vector<string> board, int n)
    {
        // do not need to check for right columns since queens havent been placed there yet
        // need to check only for -> left upper diag, left lower diag, and left row
        int Row = row;
        int Col = col;
        // upper left diag->
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        // left row->
        col = Col;
        row = Row;
        while (col >= 0)
        {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        // lower left diag->
        row = Row;
        col = Col;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }

    void doStuff(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                doStuff(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        doStuff(0, board, ans, n);
        return ans;
    }
};