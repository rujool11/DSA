// GFG floyd warshall

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == -1) mat[i][j] = 1e9; 
                // if unreachable, set to 
                if (i == j) mat[i][j] = 0; // same node cost 0
            }
        }
        
        
        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    mat[i][j] = min(mat[i][j], 
                                mat[i][k] + mat[k][j]);
                }
            }
        }
        
        for (int i=0; i<n; i++) {
            if (mat[i][i] < 0) ; // detect negative wt cycle
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == 1e9) mat[i][j] = -1; 
                // set back
            }
        }
        
        
    }
};