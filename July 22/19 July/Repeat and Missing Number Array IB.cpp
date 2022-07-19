vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n=A.size(), sum;
    vector<int> a(A.begin(),A.end()), ans;
    sort(a.begin(),a.end());
    sum=a[0];
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]) ans.push_back(a[i]);
        else sum+=a[i];
    }
    ans.push_back(n*(n+1)/2 - sum);
    
    return ans;
}
