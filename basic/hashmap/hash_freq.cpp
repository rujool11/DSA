vector<int> countFrequency(int n, int x, vector<int> &nums){
   unordered_map<int,int> hash;
   vector<int> res;

   for (auto it: nums){
      hash[it-1]++;
   }

   for (int i=0;i<n;i++){
      res.push_back(hash[i]);
   }

   return res;
}
