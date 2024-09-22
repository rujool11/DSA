// GFG number of distinct islands

class Solution {
  public:
    void bfs(int row, int col, vector<vector<int>>& grid, 
            vector<pair<int,int>>& shapes,
            int baseRow, int baseCol) {
        
        queue<pair<int,int>> q;
        q.push({row, col});
        grid[row][col] = 0; // mark as visited
        
        int m = grid.size();
        int n = grid[0].size();
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};
        
        shapes.push_back({0, 0});  // the base cell (relative to itself)

        while (!q.empty()) {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nrow = curRow + delRow[i];
                int ncol = curCol + delCol[i];
                
                bool inBounds = (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n);
                
                if (inBounds && grid[nrow][ncol] == 1) {
                    grid[nrow][ncol] = 0;  // mark as visited
                    q.push({nrow, ncol});
                    shapes.push_back({nrow - baseRow, ncol - baseCol});
                    // relative to start position
                }
            }
        }
    }
            
    int countDistinctIslands(vector<vector<int>>& grid) {
        // Set to store "shape" of an island as a relative shape
        // use set so that duplicates are handled
        set<vector<pair<int,int>>> islands;  
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> shapes;
                    bfs(i, j, grid, shapes, i, j);
                    islands.insert(shapes);
                }
            }
        }
        
        return islands.size();
    }
};
