// GFG Dijkstras algorithm
// solved using the priority queue/ min heap method

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
                        greater<pair<int,int>>> pq;
        // greater comparator used to make min_heap, since max_heap by default
        // vector of pairs used to store pq
        
        vector<int> distance(V);
        for (int i=0; i<V; i++) distance[i] = 1e9; // can also use INT_MAX
        
        distance[S] = 0; // src
        pq.push({0, S}); // (dist, src)
        
        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto it: adj[node]) {
                int adjWt = it[1];
                int adjNode = it[0];
                
                if (dist + adjWt < distance[adjNode]) {
                    distance[adjNode] = dist + adjWt;
                    pq.push({distance[adjNode], adjNode});
                }
                
            }
        }
        
        return distance;
    }
};