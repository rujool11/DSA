// Leetcode 79. Word search

class Solution {
public:

    bool doStuff(vector<vector<char>>& board, string& word, int i, int j, int index){

        if (index == word.size()) return true; // we reached end of word and everything matched

        int m = board.size();
        int n = board[0].size();

        if (i<0 || i>=m ||j<0 || j>=n || board[i][j] != word[index]){ // check if in bounds and match 
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '*'; // mark as visited 

        bool isFound = (
            doStuff(board, word, i-1, j, index+1) || // up
            doStuff(board, word, i+1, j, index+1) || // down
            doStuff(board, word, i, j-1, index+1) || // left 
            doStuff(board, word, i, j+1, index+1) // right
        );

        board[i][j] = temp; // unmark cell

        return isFound;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        if (board.empty() || board[0].empty()) return false;
        
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == word[0] && doStuff(board, word, i,j,0)) return true;
            }
            // check only for cells whose first char matches with the first char of word
        }

        return false;
    }
};




