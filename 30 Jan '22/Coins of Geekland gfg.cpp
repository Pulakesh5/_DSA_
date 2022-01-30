// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// some kind of pre computation would work
class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> mat,int N,int k){
        // Your code goes here
        //precomputing first row and column
        for(int i=1;i<N;i++)
            mat[i][0]+=mat[i-1][0]; //+mat[i][0];
        for(int j=1;j<N;j++)
            mat[0][j]+=mat[0][j-1]; //+mat[0][j];
        
        int ans=0;
        for(int i=1;i<N;i++){
            for(int j=1;j<N;j++){
                mat[i][j] +=( mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1]);
                int cur=0;
                if(i>=k && j>=k){
                    cur = (mat[i][j]-mat[i-k][j] - mat[i][j-k] + mat[i-k][j-k]);
                }
                else if(i==k-1 && j>=k)
                {
                    cur = mat[i][j] - mat[i][j-k];
                }
                else if(j==k-1 && i>=k)
                {
                    cur = mat[i][j] - mat[i-k][j];
                }
                else if(i==k-1 && j==k-1 )
                    cur=mat[i][j];
                   
                if(cur>ans)
                    ans=cur;
            }
        }
        
        return ans;
    }  
};

// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}
  // } Driver Code Ends
