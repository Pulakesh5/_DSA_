// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool vis[502][502];
    vector<int> dx={-1,0,1,0,-1,0,1,0,1,1,-1,-1};
    vector<int> dy={0,1,0,-1,0,1,0,-1,1,-1,1,-1};
    vector<vector<char>> map;
    int numIslands(vector<vector<char>>& grid) {
        map=grid;
        int n=grid.size(),m=grid[0].size();
        //cout<<n<<" "<<m;
        memset(vis,false,sizeof(vis));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    //vis[i][j]=true;
                    dfs(i,j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(int x, int y){
        vis[x][y]=true;
        int n=map.size();
        int m=map[0].size();
        for(int i=0;i<12;i++){
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            if(new_x>=0 && new_y>=0 && new_x<n && new_y<m){
               if(map[new_x][new_y]=='1' && !vis[new_x][new_y]){
                dfs(new_x,new_y);
                } 
            }     
        }
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
