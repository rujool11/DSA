// Leetcode 721. Accounts merge

class DisjointSet {
    public: 
    vector<int> size, parent;
    DisjointSet(int n) {

        size.resize(n+1, 0);
        parent.resize(n+1);
        for (int i=0; i<=n; i++) parent[i] = i;
        
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void union_s(int u, int v) {
        int up_u = find(u);
        int up_v = find(v);

        if (up_u == up_v) return;

        if (size[up_u] < size[up_v]) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }

        else {
            parent[up_v] = up_u;
            size[up_v] += size[up_v];
        }

    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> hash; // what mail belongs to what index/account
        
        for (int i=0; i<n; i++) {
            for (int j=1; j<accounts[i].size(); j++) { // skip the name (at 0th index)
                string mail = accounts[i][j];
                // if not found in map, add to particular account
                if (hash.find(mail) == hash.end()) hash[mail] = i;
                else {
                    ds.union_s(i, hash[mail]); // connect the nodes 
                }
            }
        }

        vector<string> merged[n];
        for (auto it: hash) {
            string mail = it.first;
            int node = ds.find(it.second); // ultimate parent of that
            merged[node].push_back(mail); // add to ultimate parent
        }

        vector<vector<string>> ans;

        for (int i=0; i<n; i++) {
            if (merged[i].size() == 0) continue;
            sort(merged[i].begin(), merged[i].end()); // has to be sorted for test cases

            vector<string> temp;
            temp.push_back(accounts[i][0]); // add name

            for (auto it: merged[i]) temp.push_back(it);
            ans.push_back(temp);
        }

        return ans;
    }
};