class Solution {
public:
vector<int> FindWays(vector<vector<int>>&matrix){
    int n=matrix.size();
    vector<vector<long>> path(n,vector<long>(n,0)),adv(n,vector<long>(n,-1));
    int mod=1e9+7,i,j;
    path[0][0]=1;
    adv[0][0]==matrix[0][0];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(path[i][j]!=0){
                if(matrix[i][j]==1 && (j+1)<n){
                    path[i][j+1]=(path[i][j+1]+path[i][j])%mod;
                    adv[i][j+1]=max(adv[i][j+1],(adv[i][j]+matrix[i][j+1])%mod);
                }
                else if(matrix[i][j]==2 && (i+1)<n){
                    path[i+1][j]=(path[i][j]+path[i+1][j])%mod;
                    adv[i+1][j]=max(adv[i+1][j],(adv[i][j]+matrix[i+1][j])%mod);
                }
                else if(matrix[i][j]==3){
                    if((i+1)<n){
                    path[i+1][j]=(path[i][j]+path[i+1][j])%mod;
                    adv[i+1][j]=max(adv[i+1][j],(adv[i][j]+matrix[i+1][j])%mod);
                    }
                    if((j+1)<n){
                    path[i][j+1]=(path[i][j+1]+path[i][j])%mod;
                    adv[i][j+1]=max(adv[i][j+1],(adv[i][j]+matrix[i][j+1])%mod);
                    }
                }
            }
        }
    }
    
    if(adv[n-1][n-1]==-1) 
        adv[n-1][n-1]=0;
    return {path[n-1][n-1],adv[n-1][n-1]};
    
    
    
    // int n=a.size();
    // int i,j;
    // int m=1e9+7;
    
    // vector<vector<long>> paths(n,vector<long>(n,0)),adv(n,vector<long>(n,-1));
    // paths[0][0]=1;
    // adv[0][0]=a[0][0];
    
    // for(i=0;i<n;i++)
    // {
    //     for(j=0;j<n;j++)
    //     {
    //         if(paths[i][j]!=0)
    //         {
    //             if(a[i][j]==1 && j+1<n)
    //             {
    //                 paths[i][j+1]=(paths[i][j+1]+paths[i][j])%m;
    //                 adv[i][j+1]=max(adv[i][j+1],(adv[i][j]+a[i][j+1])%m);
    //             }
    //             else if(a[i][j]==2 && i+1<n)
    //             {
    //                 paths[i+1][j]=(paths[i+1][j]+paths[i][j])%m;
    //                 adv[i+1][j]=max(adv[i+1][j],(adv[i][j]+a[i+1][j])%m);
    //             }
    //             else if(a[i][j]==3)
    //             {
    //                 if(i+1<n)
    //                 {
    //                     paths[i+1][j]=(paths[i+1][j]+paths[i][j])%m;
    //                     adv[i+1][j]=max(adv[i+1][j],(adv[i][j]+a[i+1][j])%m);
    //                 }
    //                 if(j+1<n)
    //                 {
    //                     paths[i][j+1]=(paths[i][j+1]+paths[i][j])%m;
    //                     adv[i][j+1]=max(adv[i][j+1],(adv[i][j]+a[i][j+1])%m);
    //                 }
    //             }
    //         }
    //     }
    // }

    // if(adv[n-1][n-1]==-1)
    // adv[n-1][n-1]=0;
    
    // return {paths[n-1][n-1],adv[n-1][n-1]};
}
};
