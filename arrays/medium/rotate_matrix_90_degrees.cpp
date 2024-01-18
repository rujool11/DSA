class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose matrix and reverse rows
        // transpose matrix is same as swap along diagonal
        // [x][y] -> [y][x]

        int n = matrix.size();
        for (int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++){ //i+1, so i<n-1 in parent loop
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for (int j=0;j<n;j++){
            reverse(matrix[j].begin(),matrix[j].end());
        }

    }
};
