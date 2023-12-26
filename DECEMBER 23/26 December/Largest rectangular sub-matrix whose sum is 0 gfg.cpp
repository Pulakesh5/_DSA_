class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
      
        int n = a.size(), m = a[0].size();
        vector<vector<int>> prefixSumRows(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < m; j++) {
                sum += a[i][j];
                prefixSumRows[i][j] = sum;
            }
        }
        
        int row_start_ans = 0, row_end_ans = -1, col_start_ans = 0, col_end_ans = -1, max_area = 0;
        // Fix starting column and ending column
        for(int col_start = 0; col_start < m; col_start++) {
            for(int col_end = col_start; col_end < m; col_end++) {
                // Find the maximum number of consecutive rows with total sum = 0
                vector<int> v(n);
                for(int i = 0; i < n; i++)
                    v[i] = ((col_start == 0) ? prefixSumRows[i][col_end] : prefixSumRows[i][col_end] - prefixSumRows[i][col_start - 1]);
                
                // Find the longest subarray in 'v' with sum = 0
                map<int, int> mp;
                int sum = 0, row_start = 0, row_end = -1;
                for(int i = 0; i < n; i++) {
                    sum += v[i];
                    if(v[i] == 0 && row_end == -1) {
                        row_start = i;
                        row_end = i;
                    }
                    if(sum == 0 && i + 1 > row_end - row_start + 1) {
                        row_start = 0;
                        row_end = i;
                    }
                    if(mp.find(sum) != mp.end() && i - mp[sum] > row_end - row_start + 1) {
                        row_start = mp[sum] + 1;
                        row_end = i;
                    }
                    if(mp.find(sum) == mp.end())
                        mp[sum] = i;
                }
                int area = (row_end - row_start + 1) * (col_end - col_start + 1);
                if(area > max_area) {
                    max_area = area;
                    row_start_ans = row_start;
                    row_end_ans = row_end;
                    col_start_ans = col_start;
                    col_end_ans = col_end;
                }
            }
        }
        
        vector<vector<int>> ans;
        for(int i = row_start_ans; i <= row_end_ans; i++) {
            vector<int> row;
            for(int j = col_start_ans; j <= col_end_ans; j++)
                row.push_back(a[i][j]);
            ans.push_back(row);
        }
        
        return ans;
        // int n=a.size(), m=a[0].size();
        // vector<vector<int>> dp(n+2, vector<int>(m+2,0));
        
        // int startX=-1, startY=-1, endX=-1, endY=-1, prevX, prevY; 
        // int areaSubMatrix=0, sum;
        
        // map<int, pair<int,int>> sumExists;
        // sumExists[0] = {-1, -1};
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //     {
        //         sum = dp[i+1][j] + (dp[i][j+1]-dp[i][j]) + a[i][j];
                
        //         dp[i+1][j+1] = sum;
                
        //         if(sumExists.find(sum)!=sumExists.end())
        //         {
        //             prevX=sumExists[sum].first;
        //             prevY=sumExists[sum].second;
                    
        //             if((i-prevX)*(j-prevY) > areaSubMatrix)
        //             {
        //                 startX = prevX;
        //                 startY = prevY;
                        
        //                 endX = i;
        //                 endY = j;
        //                 areaSubMatrix = (i-prevX)*(j-prevY);
        //             }
        //         }
        //         else
        //             sumExists[sum] = {i, j};
        //     }
        // }
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //         cout<<dp[i+1][j+1]<<" ";
        //     cout<<endl;
        // }
        
        
        // vector<vector<int>> subMatrix;
        
        // for(int i=startX+1; i<=endX; i++)
        // {
        //     vector<int> row;
        //     for(int j=startY+1; j<=endY; j++)
        //         row.push_back(a[i][j]);
        //     subMatrix.push_back(row);
        // }
        
        // return subMatrix;
        
        
        
    }
//   1  3  6
//  -2 -2  0
//  -1  6  13
};
