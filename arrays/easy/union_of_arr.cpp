vector<int> sortedArray(vector<int>& a, const std::vector<int>& b) {
    int n = a.size();
    int m = b.size();

    vector<int> res;

    int i = 0;
    int j = 0;

    while (i<n && j<m){
        if (a[i]<=b[j]){
            if (res.empty()||res.back()!=a[i]){
                res.push_back(a[i]);
            }
            i++;
        }
        else {
            if (res.empty()||res.back()!=b[j]){
                res.push_back(b[j]);
            }
            j++;
        }
    }

    while (i<n){
        if (res.empty()||res.back()!=a[i]){
            res.push_back(a[i]);
        }
        i++;
    }

    while (j<m){
        if (res.empty()||res.back()!=b[j]){
            res.push_back(b[j]);
        }
        j++;
    }
    
    return res;
}

