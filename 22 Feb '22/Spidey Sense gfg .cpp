//Similar to rotten oranges
// how do you make sure open spaces are reached at the shortest distance
// Think graph traversals
class Solution{

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        // Your code goes here
        queue<pair<int,int>> q;
        vector<vector<int>> ans(M, vector<int> (N,-1));
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(matrix[i][j]=='B'){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        int level=0;
        while(!q.empty()){
            int size=q.size();
            level++;
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int r=it.first +dx[i], c=it.second + dy[i];
                    
                    if(r<0 || c<0 || r>=M || c>=N || matrix[r][c]!='O' || ans[r][c]!=-1)
                        continue;
                    ans[r][c]=level;
                    q.push({r,c});
                }
            }
        }
        return ans;
    } 
};
