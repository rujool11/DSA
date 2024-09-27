// GFG Alien dictionary 

class Solution {
  public:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> res;
	    
        int indegree[V] =  {0};
        
        for (int i=0; i<V; i++) {
            for (auto it: adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for (int i=0; i<V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            res.push_back(node);
            // node is in topo sort, so remove from indegree
            
            for (auto it: adj[node]) {
                indegree[it]--; //node is now removed from its adj's indegree
                if (indegree[it] == 0) q.push(it);
                // if indegree 0, push it to q
                
            }
            
        }
        
        return res;
    }
    
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];
        
        for (int i=0; i<n-1; i++) {  // go only till n-1 since we need pairs
            string a = dict[i];
            string b = dict[i+1];
            
            // compare character by character
            int len = min(a.size(), b.size());
            
            for (int x=0; x<len; x++) {
                if (a[x]!=b[x]) {
                    adj[a[x] - 'a'].push_back(b[x] - 'a');
                    break; // break after differentiating factor found
                }
            }
        }
        
       vector<int> topo = topoSort(k, adj);
       string res = "";
       for (auto it: topo) {
           res.push_back(char(it + 'a'));
       }
       
       return res;
        
    }
};