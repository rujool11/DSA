int secondLargest(vector<int> a, int n){
    int max = a[0];
    int s_max = -1;
    for (int i=1;i<n;i++){
        if (a[i]>max){
            s_max = max;
            max = a[i];
        }
        else if (a[i]<max && a[i]>s_max){s_max = a[i];}
    }

    return s_max;
}

int secondSmallest(vector<int> a, int n){
    int min = a[0];
    int s_min = INT_MAX;
    for (int i=1;i<n;i++){
        if (a[i]<min){
            s_min = min;
            min = a[i];
        }
        else if (a[i]>min && a[i]<s_min){s_min = a[i];}
    }

    return s_min;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int sec_l = secondLargest(a,n);
    int sec_s = secondSmallest(a,n);
    return {sec_l,sec_s};

}
