class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // instead of using two vars for row/col flags, we use the 0th r/c of matrix itself
        // since the 0th r/c of matrix have a common elemnts, use a variable to store that 
        // (col_00 stores for 0th col, and matrix[0][0] is for 0th row)
        // O(1) space complexity

        int col_00 = 1;

        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]==0){
                    matrix[i][0] = 0;
                    if (j!=0){matrix[0][j] = 0;}
                    else {col_00 = 0;} 
                }
            }
        }

        for (int i=1;i<matrix.size();i++){
            for (int j=1;j<matrix[0].size();j++){
                if (matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0){
            for (int j=0;j<matrix[0].size();j++){matrix[0][j]=0;}
        }

        if (col_00 == 0){
            for (int i=0;i<matrix.size();i++){matrix[i][0]=0;}
        }

    }
};
