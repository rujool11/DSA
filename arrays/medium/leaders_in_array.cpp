vector<int> superiorElements(vector<int>&a) {
   vector<int> ans;
   int maxEl = INT_MIN;

   for (int i=a.size()-1;i>=0;i++){
       if (a[i]>maxEl){
           ans.push_back(a[i]);
           maxEl = a[i];
           }

   }

   sort(ans.begin(),ans.end()); // since we need to return sorted array, not part of logic
   return ans;

