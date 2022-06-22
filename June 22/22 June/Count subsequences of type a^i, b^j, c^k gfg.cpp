class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
        int n=s.size();
        vector<vector<long long>> count(3,vector<long long>(n+1,0));
        int mod=1e9+7;
        
        for(int i=0;i<n;i++){
            count[0][i+1]= s[i]=='a'? (2*count[0][i]+1)%mod : count[0][i];
            count[1][i+1]= s[i]=='b'? (2*count[1][i]+count[0][i+1])%mod : count[1][i];
            count[2][i+1]= s[i]=='c'? (2*count[2][i]+count[1][i+1])%mod : count[2][i];
        }
        
        return count[2][n];
        
    }
};
