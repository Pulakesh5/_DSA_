int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    vector<int> pre(n+1,0),suf(n+2,0);
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i]+A[i];
        suf[i+1]=suf[i]+A[n-1-i];
    }
    int ans=INT_MIN;
    for(int i=0;i<=B;i++){
        ans=max(ans,pre[i]+suf[B-i]);
    }
    return ans;
}
