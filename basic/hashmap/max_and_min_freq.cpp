vector<int> getFrequencies(vector<int>& v) {
    unordered_map<int, int> freqs;

    for (auto num : v) {
        freqs[num]++;
    }

    vector<int> res(2);
    res[0] = v[0];
    res[1] = v[0];

    for (auto it : freqs) {
        if (freqs[res[0]] < it.second) {
            res[0] = it.first;
        } else if (freqs[res[0]] == it.second && it.first < res[0]) {
            res[0] = it.first;
        }

        if (freqs[res[1]] > it.second) {
            res[1] = it.first;
        } else if (freqs[res[1]] == it.second && it.first < res[1]) {
            res[1] = it.first;
        }
    }



    return res;
}
