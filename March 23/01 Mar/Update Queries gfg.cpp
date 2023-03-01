class Solution{
    public:
        vector<int> updateQuery(int n,int Q,vector<vector<int>> &U)
        {
            int v[n+1][20];
            memset(v, 0, sizeof(v));
            
            for(auto a : U){
                for(int bit = 0; bit < 20; ++bit){
                    v[a[0]-1][bit] += ((a[2]>>bit)&1);
                    v[a[1]][bit] -= ((a[2]>>bit)&1);
                }
            }
            
            vector<int> a(n);
            for(int bit = 0; bit < 20; ++bit){
                for(int i = 0; i < n; ++i){
                    if(i)v[i][bit] += v[i-1][bit];
                    a[i] += (1<<bit)*(v[i][bit]>0);
                }
            }
            
            return a;
        }
};
