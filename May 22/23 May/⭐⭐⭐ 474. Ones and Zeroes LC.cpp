/*
This is one of the most exciting questions in my coding journey if not the most
I tried solving it in ngreedy way, obviously that didn't work
I solved it using 3d dp on my way and that is the most exciting part
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int _zero, int _one) {
        int N=strs.size();
        int count[N][2];
        int zero=0,one=0;
        
        for(int i=0;i<N;i++){
            int len=strs[i].size();
            zero=0;one=0;
            for(int j=0;j<len;j++){
                if(strs[i][j]=='0')
                    zero++;
                else
                    one++;
            }
            count[i][0]=zero;
            count[i][1]=one;
        }
        
        int dp[N+1][_zero+1][_one+1];
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=N;i++){
            for(int j=0;j<=_zero;j++){
                for(int k=0;k<=_one;k++){
                    if(count[i-1][0]<=j && count[i-1][1]<=k){
                        dp[i][j][k]=max(dp[i-1][j-count[i-1][0]][k-count[i-1][1]]+1                          ,dp[i-1][j][k]);
                    }
                    else
                        dp[i][j][k]=dp[i-1][j][k];
                }
            }
        }
        
        return dp[N][_zero][_one];
       
    }
};
