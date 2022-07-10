bool solve(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> mat(r,vector<int>(c));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cin>>mat[i][j];
    }
    
    vector<vector<int>> f(r+1,vector<int>(c+1)),s(r+1,vector<int>(c+1));
    for(int j=0;j<c;j++)
    {
        f[0][j]=mat[0][j];
        s[0][j]=mat[0][j];
    }
    
    for(int i=0;i<r;i++){
        f[i][0]=mat[i][0];
        s[i][c-1]=mat[i][c-1];
    }
    
    int x=0,y=0;
    // for main diagonals
    for(int i=1;i<r;i++){
        y=i;x=1;
        while(x<c && y<r){
            f[y][x]=f[y-1][x-1]+mat[y][x];
            x++;y++;
        }
    }
    
    for(int j=2;j<c;j++){
        y=1;x=j;
        while(x<c && y<r){
            f[y][x]=f[y-1][x-1]+mat[y][x];
            x++;y++;
        }
    }
    // for secondary diagonals
    for(int i=1;i<r;i++){
        y=i;x=c-2;
        while(x>=0 && y<r){
            s[y][x]=s[y-1][x+1]+mat[y][x];
            x--;y++;
        }
    }
 
    for(int j=c-3;j>=0;j--){
        y=1;x=j;
        while(x>=0 && y<r){
            s[y][x]=s[y-1][x+1]+mat[y][x];
            x--;y++;
        }
    }
    int maxSum=INT_MIN,mn,sum=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            //cerr<<"("<<i<<","<<j<<") -> ";
            mn=min(r-1-i,c-1-j);
            sum=f[i+mn][j+mn];
            //cerr<<sum<<", ";
            mn=min(r-1-i,j);
            sum+=s[i+mn][j-mn];
            //cerr<<sum<<", ";
            sum-=mat[i][j];
            //cerr<<sum<<"\n";
            if(sum>maxSum){
                maxSum=sum;
            }
            
        }
        //cerr<<endl;
    }
    cout<<maxSum;
    
    
    return 0;
    
}
