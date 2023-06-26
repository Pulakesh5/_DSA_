class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& zeroes) {
        vector<vector<int>> mines(n,vector<int>(n,1));
        vector<vector<int>> left(n+2,vector<int>(n+2,0));
        vector<vector<int>> right(n+2,vector<int>(n+2,0));
        vector<vector<int>> up(n+2,vector<int>(n+2,0));
        vector<vector<int>> down(n+2,vector<int>(n+2,0));
        for(auto zero:zeroes)
            mines[zero[0]][zero[1]] = 0;

        
        //// moving right
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mines[i][j])
                {
                    if(j>0)
                        right[i][j] = right[i][j-1];
                    right[i][j]+=mines[i][j];
                }
                
            }
        }
        
        ////moving left
        for(int i=0; i<n; i++)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(mines[i][j])
                {
                    if(j+1<n)
                        left[i][j] = left[i][j+1];
                    left[i][j]++;
                }
            }
        }
        // for(auto vec:left)
        // {
        //     for(int num:vec)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        ////moving down
        for(int j=0; j<n; j++)
        {
            for(int i=0; i<n; i++)
            {
                if(mines[i][j])
                {   
                    if(i>0)
                        down[i][j] = down[i-1][j];
                    down[i][j]+=mines[i][j];
                }
            }
        }
        
        ////moving up
        for(int j=0; j<n; j++)
        {
            for(int i=n-1; i>=0; i--)
            {
                if(mines[i][j])
                {
                    if(i!=(n-1))
                        up[i][j] = up[i+1][j];
                    up[i][j]+=mines[i][j];
                }
            }
        }

        // for(auto vec:up)
        // {
        //     for(int num:vec)
        //         cout<<num<<" ";
        //     cout<<endl;
        // } 
        // cout<<"index\tdown\tup\tleft\tright\n";
        int plusSign = 0, plus;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mines[i][j]==0)
                    continue;
                if(i==0 || j==0 || i==(n-1) || j==(n-1))
                {
                    if(mines[i][j])
                        plusSign = max(plusSign, 1);
                    continue;
                }
                // cout<<i<<","<<j<<"\t\t";
                // cout<<down[i-1][j]<<'\t'<<up[i+1][j]<<"\t"<<left[i][j+1]<<'\t'<<right[i][j-1]<<endl;
                plus = down[i-1][j];
                plus = min(plus, up[i+1][j]);
                plus = min(plus, left[i][j+1]);
                plus = min(plus, right[i][j-1]);
                plusSign = max(plusSign, plus+1);
            }
        }
        return plusSign;
    }
};
