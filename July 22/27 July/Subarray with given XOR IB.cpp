int Solution::solve(vector<int> &A, int B) {
    map<int,int> mp;
    int Xor=0,n=A.size(),ans=0;
    mp[0]=1;
    for(int i=0;i<n;i++){
        Xor^=A[i];
        if(mp.find(Xor^B)!=mp.end())
            ans+=mp[Xor^B];
        mp[Xor]++;
    }
    return ans;
}
