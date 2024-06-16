// GFG rat in a maze, might be issue with test cases/ review code once

class Solution{
    public:
    
    void doStuff(vector<string>& ans, string helper, vector<vector<int>>& visited, vector<vector<int>>& m, int n, int i, int j) {
        if (i==n-1 && j==n-1) {
            ans.push_back(helper);
            return;
        }
        
        // check if next index is inside boundary and then go ->
        
        // down 
        if (i+1<n && !visited[i+1][j] && m[i+1][j]) {
            visited[i+1][j] = 1;
            doStuff(ans, helper + 'D', visited, m, n, i+1, j);
            visited[i+1][j] = 0;
        }
        
        // left 
        if (j-1>=0 && !visited[i][j-1] && m[i][j-1]) {
            visited[i][j-1] = 1;
            doStuff(ans, helper + 'L', visited, m, n, i, j-1);
            visited[i][j-1] = 0;
        }
        
        //right
        if (j+1<n && !visited[i][j+1] && m[i][j+1]) {
            visited[i][j+1] = 1;
            doStuff(ans, helper + 'R', visited, m, n, i, j+1);
            visited[i][j+1] = 0;
        }
        
        //up
        if (i-1>=0 && !visited[i-1][j] && m[i-1][j]) {
            visited[i-1][j] = 1;
            doStuff(ans, helper + 'U', visited, m, n, i-1, j);
            visited[i-1][j] = 0;
        }
        
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string helper = "";
        vector<vector<int>> visited(n, vector<int> (n,0));
        if (m[0][0] == 1) doStuff(ans, helper, visited,  m, n, 0, 0);
        return ans;
    }
};