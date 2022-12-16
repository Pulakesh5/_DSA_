    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int x, int y)
    {
        // code here
       set<pair<int,int>>st;
        queue<pair<int,int>> q;
        
        int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
        int ni,nj,i,j;
        
        i=x;
        j=y;
        
        q.push({i,j});
        st.insert(make_pair(i,j));
        
        while(!q.empty() && ty>=0)
        {
            int qs=q.size();
            for(int c=0;c<qs;c++)
            {
                auto pr=q.front();
                
                i=pr.first;
                j=pr.second;
                
                q.pop();
                
                for(int k=0;k<4;k++)
                {
                    ni=i+dx[k];
                    nj=j+dy[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && st.find({ni,nj})==st.end())
                    {
                        q.push({ni,nj});
                        st.insert(make_pair(ni,nj));
                    }
                }
                if(j&1)
                {
                    ni=i+1;
                    nj=j+1;
                    if(ni>=0 && ni<n && nj>=0 && nj<m && st.find({ni,nj})==st.end())
                    {
                        q.push({ni,nj});
                        st.insert(make_pair(ni,nj));
                    }
                    ni=i+1;
                    nj=j-1;
                    if(ni>=0 && ni<n && nj>=0 && nj<m && st.find({ni,nj})==st.end())
                    {
                        q.push({ni,nj});
                        st.insert(make_pair(ni,nj));
                    }
                }
                else
                {
                    ni=i-1;
                    nj=j+1;
                    if(ni>=0 && ni<n && nj>=0 && nj<m && st.find({ni,nj})==st.end())
                    {
                        q.push({ni,nj});
                        st.insert(make_pair(ni,nj));
                    }
                    ni=i-1;
                    nj=j-1;
                    if(ni>=0 && ni<n && nj>=0 && nj<m && st.find({ni,nj})==st.end())
                    {
                        q.push({ni,nj});
                        st.insert(make_pair(ni,nj));
                    }
                }
            }
            ty--;
        }
        int ans=0;
        while(!q.empty())
        {
            auto pr=q.front();
                
            i=pr.first;
            j=pr.second;
            
            ans+=mat[i][j];
            
            q.pop();
        }
        return ans;
        
    }
