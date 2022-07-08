class Solution{
public:
    void parenthesize(vector<vector<int>> &bracket, int i, int j, char &mat, string &chain){
        if(i==j){
            chain+=mat;
            mat++;
            return;
        }
        
        chain+='(';
        parenthesize(bracket,i,bracket[i][j],mat,chain);
        parenthesize(bracket, bracket[i][j]+1,j,mat,chain);
        chain+=')';
    }

    string matrixChainOrder(int p[], int n){
        // code here
        vector<vector<int>> dp(n,vector<int>(n)), bracket(n,vector<int>(n));
        
        for(int i=1;i<n;i++) dp[i][i]=0;
        // len is matrix chain length
        int mul=0;
        for(int len=2;len<=(n-1);len++){
            
            for(int i=1;i<(n-len+1);i++){
                
                int j=i+len-1;// len = j-i+1
                dp[i][j]=INT_MAX;
                
                for(int k=i;k<j;k++){
                    
                    mul=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                    
                    if(mul<dp[i][j]){
                        dp[i][j]=mul;
                        bracket[i][j]=k;
                    }
                }
            }
        }
        
        char mat='A';
        string chain="";
        parenthesize(bracket,1,n-1,mat,chain);
        
        return chain;
    }
};
