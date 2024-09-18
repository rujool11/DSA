// Leetcode 733. Flood Fill
// BFS solution ->

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Initialize BFS with a queue
        queue<pair<int, int>> q;
        q.push({sr, sc});

        int m = image.size();
        int n = image[0].size();
        int start = image[sr][sc];
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // If the start pixel is already the target color, return early
        if (start == color) return image;

        // Change the color of the starting pixel
        image[sr][sc] = color;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Explore 4 directions: up, right, down, left
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                bool inBounds = (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n);
                // If the neighbor has the same color as the starting pixel, fill it and continue the BFS
                if (inBounds && image[nrow][ncol] == start) {
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }

        return image;
    }
};

//-----------------------------------------------------------------------------------------------------
// DFS solution ->


class Solution {
private:
    void dfs(vector<vector<int>>& image, int row, int col, vector<vector<int>>& ans,
            int color, int delRow[], int delCol[], int start) {
        ans[row][col] = color;

        for (int i=0; i<4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            bool inBounds = (nrow>=0 && ncol>=0 && 
                            nrow<image.size() && ncol<image[0].size());

            if (inBounds && image[nrow][ncol] == start && ans[nrow][ncol]!=color) {
                dfs(image, nrow, ncol, ans, color,
                    delRow, delCol, start);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};
        dfs(image, sr, sc, ans, color, delRow, delCol, image[sr][sc]);
        return ans;
    }
};

