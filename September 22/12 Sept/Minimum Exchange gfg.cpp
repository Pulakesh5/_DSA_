int MinimumExchange(vector<vector<char>>matrix){
    // Code here
    int count1=0,count2=0;
    int n=matrix.size(),m=matrix[0].size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((i+j)&1)
            {
                if(matrix[i][j]=='A')
                    count1++;
                 else if(matrix[i][j]=='B')
                    count2++;
            }
            else
            {
                 if(matrix[i][j]=='B')
                    count1++;
                 else if(matrix[i][j]=='A')
                    count2++;
            }
        }
    }
    return m*n-max(count1,count2);
}
