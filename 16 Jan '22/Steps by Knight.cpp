// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
/*
    Solution idea : 
                    Is this problem looking similar? use the same method otherwise look for the solution
                    lok at hint
                    
*/
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    pair<int,int> Knight={KnightPos[0],KnightPos[1]}, Target={TargetPos[0],TargetPos[1]};
	    vector<int> dx={-2,-1,1,2,-2,-1,1,2},dy={-1,-2,-2,-1,1,2,2,1};
	    int dp[N+1][N+1];
	    memset(dp, -1,sizeof(dp));
	    dp[Knight.first][Knight.second]=0;
	    queue<pair<int,int>> q;
	    q.push(Knight);
	    int nx,ny;
	    while(!q.empty()){
	        auto it=q.front();
	        int x=it.first, y=it.second;
	        q.pop();
	        for(int i=0;i<8;i++){
	            nx=x+dx[i];
	            ny=y+dy[i];
	            if(nx<1 || ny<1 || nx>N || ny> N || dp[nx][ny]!=-1)
	                continue;
	                dp[nx][ny]=1+dp[x][y];
	                q.push({nx,ny});
	        }
	    }
	    return dp[Target.first][Target.second];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
