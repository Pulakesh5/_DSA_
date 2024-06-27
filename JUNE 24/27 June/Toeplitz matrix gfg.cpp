bool isToeplitz(vector<vector<int>>& mat) {
    // code here
    
    int Row = mat.size(), Column = mat[0].size();
    int prev = mat[0][0];
    for(int i=1, j=1; i<Row && j<Column; i++, j++)
    {
        if(mat[i][j]!=prev)
            return false;
    }
    // cout<<"Main diagonal checked\n";
    for(int r=1; r<Row; r++)
    {
        prev = mat[r][0];
        // cout<<prev<<endl;
        for(int i=r+1, j=1; i<Row && j<Column; i++, j++)
        {
            // cout<<i<<", "<<j<<" : "<<mat[i][j]<<endl;
            if(mat[i][j]!=prev)
            {
                // cout<<"Did not matched at "<<i<<", "<<j<<"\n";
                // cout<<mat[i][j]<<" "<<prev<<endl;
                return false;
            }
        }
    }
    // cout<<"Lower Triangle checked\n";
    // 6 4 6 7 3 0 0
    // 10 6 4 6 7 3 0
    // 2 10 6 4 6 7 3 
    // 3 2 10 6 4 6 7
    for(int c=1; c<Column; c++)
    {
        prev = mat[0][c];
        // cout<<prev<<endl;
        for(int i=1, j=c+1; i<Row && j<Column; i++, j++)
        {
            // cout<<i<<", "<<j<<" : "<<mat[i][j]<<endl;
            if(mat[i][j]!=prev)
            {
                // cout<<"Did not matched at "<<i<<", "<<j<<endl;
                // cout<<mat[i][j]<<" "<<prev<<endl;
                return false;
            }
        }
    }
    // cout<<"Upper Triangle checked\n";
    // cout<<"All checked\n";
    return true;
    
}
