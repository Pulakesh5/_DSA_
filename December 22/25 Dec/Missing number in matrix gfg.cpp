    long long int MissingNo(vector<vector<int> >& matrix) {
        // Code here
        int n=matrix.size();
        
        vector<long long> row(n+1),col(n+1);
        
        pair<int,int> pos=make_pair(-1,-1);
        
        long long rowSum,colSum;
        long long mainDiag=0,auxDiag=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    pos=make_pair(i,j);
                    continue;
                }
                
                if(i==j) mainDiag+=matrix[i][j];
                if(i==(n-1-j)) auxDiag+=matrix[i][j];
                
                row[i]+=matrix[i][j];
                col[j]+=matrix[i][j];
            }
        }
        
        for(int j=0;j<n;j++)
        {
            if(j==pos.second)   continue;
            colSum=col[j];
            break;
        }

        for(int i=0;i<n;i++)
        {
            if(i==pos.first)    continue;
            rowSum=row[i];
            break;
        }
        
        for(int k=0;k<n;k++)
        {
            if(k!=pos.first && row[k]!=rowSum) return -1;
            
            if(k!=pos.second && col[k]!=colSum) return -1;
        }
        
        if((rowSum-row[pos.first])!=(colSum-col[pos.second])) return -1;
        
        long long ans=(rowSum-row[pos.first]);
        
        if(pos.first==pos.second)
        {
            mainDiag+=ans;
        }
        if(pos.first==(n-1-pos.second))
        {
            auxDiag+=ans;
        }
        
        
        if(ans<=0 || mainDiag!=auxDiag) return -1;
        
        return ans;
    }
