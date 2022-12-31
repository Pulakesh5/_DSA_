class Solution {
public:
    int uniquePath=0;
    vector<int> dx={-1,1,0,0}, dy={0,0,-1,1};

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        set<vector<int>> st;
        vector<int> start, end;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                    st.insert({i,j});
                else if(grid[i][j]==1)
                    start={i,j};
                else if(grid[i][j]==2)
                    end={i,j};
            }
        }
        st.insert(end);

        backtrack(n,m,st,start,end);

        return uniquePath;
    }

    void backtrack(int n, int m, set<vector<int>> &st, vector<int> cell, vector<int> &end)
    {
        if(cell==end && st.empty())
        {
            uniquePath++;
            return;
        }
        int nx,ny;
        vector<int> v;
        for(int k=0;k<4;k++)
        {
            nx=cell[0]+dx[k];
            ny=cell[1]+dy[k];
            v={nx,ny};

            if(nx>=0 && nx<n && ny>=0 && ny<m && st.find(v)!=st.end())
            {
                
                st.erase(st.find(v));
                backtrack(n,m,st,v,end);
                st.insert(v);
            }
        }
    }
};
