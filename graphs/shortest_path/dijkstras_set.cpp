// GFG Dijkstra's Algorithm 
// solved using set

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st;
        vector<int> distance(V, INT_MAX);
        
        st.insert({0, S});
        distance[S] = 0;
        
        while (!st.empty()) {
            auto it = *(st.begin()); // value at first address of set, i.e smallest
            int node = it.second;
            int dist = it.first;
            
            st.erase(it);  // remove from set
            
            for (auto x: adj[node]) {
                int adjNode = x[0];
                int edgeWt = x[1];
                
                if (dist + edgeWt < distance[adjNode]) {
                    if (distance[adjNode] != INT_MAX) { // someone already reached
                        st.erase({distance[adjNode], adjNode});
                    } // this path is not needed since shorter found
                    
                    distance[adjNode] = dist + edgeWt;
                    st.insert({distance[adjNode], adjNode});
                }
            }
            
        }
        
        return distance;
    }
};