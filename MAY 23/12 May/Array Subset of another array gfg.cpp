string isSubset(int a1[], int a2[], int n, int m) {
    if(n<m) return "No";
    map<int, int> freq1, freq2;
    for(int i=0; i<n;i++)
        freq1[a1[i]]++;
    for(int i=0; i<m;i++)
        freq2[a2[i]]++;
    for(auto it:freq2)
    {
        if(freq1.find(it.first)==freq1.end() || freq1[it.first]<it.second)
            return "No";
    }
    return "Yes";
}
