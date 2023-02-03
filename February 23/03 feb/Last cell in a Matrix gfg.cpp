pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        vector<vector<int>> dir={{0,1}, {1,0}, {0,-1}, {-1,0}};
        int n=matrix.size(), m=matrix[0].size();
        
        int i=0,j=0,k=0;
        pair<int,int> ans;
        
        while(i>=0 && i<n && j>=0 && j<m)
        {
            ans={i,j};
            if(matrix[i][j]==1)
            {
                matrix[i][j]=0;
                k=(k+1)%4;
            }
            i=i+dir[k][0];
            j=j+dir[k][1];
        }
        return ans;
    }
