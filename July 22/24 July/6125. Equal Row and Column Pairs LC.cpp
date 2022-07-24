class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> Rows,Columns;
        int n=grid.size();
        vector<int> t(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            //cout<<i<<" "<<ans<<endl;
            ans+=Columns[grid[i]];
            Rows[grid[i]]++;
            //cout<<ans<<endl;
            for(int j=0;j<n;j++)
                t[j]=grid[j][i];
            ans+=Rows[t];
            //cout<<ans<<endl;
            Columns[t]++;
        }
        return ans;
    }
};

/*********************************************************************************************/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> Rows,Columns;
        int n=grid.size();
        vector<int> t(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                bool flag=true;
                for(int k=0;k<n && flag;k++){
                    if(grid[i][k] != grid[k][j])
                        flag=false;
                }
                ans+=flag;
            }
        }
        return ans;
    }
};
