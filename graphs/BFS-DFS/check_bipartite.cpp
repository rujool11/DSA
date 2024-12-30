// Leetcode 785. Is Graph Bipartite ?


// basically, 2 color graph coloring
// cannot be bipartite if odd length cycle
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int color, int colors[], int node) {
        colors[node] = color;

        // if any dfs call returns false, graph not bipartite
        for (auto it: graph[node]) {
            if (colors[it] == -1) {
                // call dfs, return false if returns false
                if (!dfs(graph, !color, colors, it)) return false;
            }
            
            // already colored, and same color as current, then not bipartite
            else if (colors[it] == color) return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // graph that can be colored with 2 colors such 
        // that no two adjacent nodes have the same color

        int V = graph.size();
        int colors[V];
        for (int i=0; i<V; i++) colors[i] = -1;
        
        for (int i=0; i<V; i++) {
            // start coloring with color 0
            if (colors[i] == -1)
                if (!dfs(graph, 0, colors, i)) return false;
        }

        return true;

    }
};