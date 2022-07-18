class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[]) {
        // code here
        vector<vector<int>> sum(R+1,vector<int>(C+1,0));
        
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
                sum[i][j]=M[i-1][j-1]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
            
        vector<int> ans(Q,0);
        for(int q=0;q<Q;q++){
            int x=q_i[q]+1,y=q_j[q]+1,side=1,count=M[x-1][y-1];
            
            while((x-side)>=0 && (y-side)>=0 && x<=R && y<=C){
                count=sum[x][y]-sum[x-side][y]-sum[x][y-side]+sum[x-side][y-side];
                if(count <= K)
                    ans[q]=side;
                else
                    break;
                x+=1;
                y+=1;
                side+=2;
            }
        }
        
        return ans;
    }
};
