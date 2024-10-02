// GFG path with minimum effort
// dijkstras

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // dijkstras weighted
        
        priority_queue<pair<int, pair<int,int>>,
                    vector<pair<int, pair<int,int>>>,
                    greater<pair<int, pair<int,int>>>> pq;
        
        vector<vector<int>> distance(rows, vector<int>(columns, INT_MAX));
        
        pq.push({0, {0,0}});
        distance[0][0] = 0;
        
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, -1, 0, 1};
            
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if (row == rows-1 && col == columns-1) return diff;
            
            for (int i=0; i<4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                bool inBounds = (nrow>=0 && ncol>=0 && ncol<columns && nrow<rows);
                
                if (inBounds) {
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]),
                                        diff);
                                        
                    if (newEffort < distance[nrow][ncol]) {
                        distance[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        
        return 0;
    }
};