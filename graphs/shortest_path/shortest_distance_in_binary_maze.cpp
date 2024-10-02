// GFG shortest distance in binary maze

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        // dijkstras algo -> can use q instead of pq, because not weighted
        queue<pair<int, pair<int,int>>> q; // (dist, (row, col))
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> distance(n, vector<int> (m, INT_MAX));
        
        int srcr = source.first;
        int srcc = source.second;
        int destr = destination.first;
        int destc = destination.second;
        
        if (srcr == destr && srcc == destc) return 0; // if src == dest
        
        distance[srcr][srcc] = 0;
        q.push({0, {srcr, srcc}});
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            int delRow[4] = {-1, 0, 1, 0};
            int delCol[4] = {0, -1, 0, 1};
            
            for (int i=0; i<4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                bool inBounds = (nrow>=0 && ncol>=0 && nrow<n && ncol<m);
                
                if (inBounds && grid[nrow][ncol] == 1 && dist + 1 < distance[nrow][ncol]) {
                    distance[nrow][ncol] = dist + 1;
                    q.push({1+dist, {nrow, ncol}});
                    
                    if (nrow == destr && ncol == destc) return 1 + dist; 
                    // ^ since unit weights this will be shortest
                }
            }
        }
        
        return -1; // node never reached in dikjstra
    }
};