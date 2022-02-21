class Solution{
    public:
    // Don't know how this is relate to Matrix Chain Multiplication, but it taught me a lot of good concept
    // No of subtrees with given no of nodes
    // How they help deciding which tree structure to make
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        //int* pre=new int(n+1);
        int pre[n+1];
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++)
        {
            vp[i].first=keys[i];
            vp[i].second=freq[i];
        }
        sort(vp.begin(),vp.end());
        for(int i=0;i<n;i++)
        {
            keys[i]=vp[i].first;
            freq[i]=vp[i].second;
        }
        
        pre[0]=0;
        for(int i=1;i<=n;i++)
            pre[i]=pre[i-1]+freq[i-1];
            
        for(int gap=0; gap<n; gap++){
            for(int i=0,j=gap;i<n && j<n ; i++,j++){
                if(gap==0)
                    dp[i][j]=freq[i];
                else if(gap==1){
                    int f1=dp[i][j-1];
                    int f2=dp[i+1][j];
                    dp[i][j]=min((f1 + 2*f2), (2*f1 + f2));
                    //dp[i][j]=min(freq[i]+freq[j]*2, freq[i]*2 + freq[j]);
                }
                else{
                    int mn=100000000;
                    for(int k=i;k<=j;k++){
                        int f1=( k==0? 0: dp[i][k-1]);
                        int f2=( k==j? 0: dp[k+1][j]);
                        if(f1+f2<mn)
                            mn=f1+f2;
                    }
                    dp[i][j]=mn+pre[j+1]-pre[i];
                }
            }
        }
        return dp[0][n-1];
    }
};
