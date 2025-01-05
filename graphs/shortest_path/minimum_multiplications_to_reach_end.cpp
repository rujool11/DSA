// GFG minimum multiplications to reach end

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        if (start == end) return 0; 
        queue<pair<int,int>> q;
        q.push({start, 0});
        
        int mod = 100000;
        vector<int> distance(100000, INT_MAX);
        distance[start] = 0;
        
        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            for (auto it: arr) {
                int num = (it * node) % mod;
                
                if (steps + 1 < distance[num]) {
                    distance[num] = steps + 1;
                    if (num == end) return steps + 1;
                    q.push({num, steps+1});
                }
                
            }
            
        }
        
        return -1;
        
    }
};