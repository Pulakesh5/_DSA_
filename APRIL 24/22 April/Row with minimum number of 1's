class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        // code here
        int minCount = m+1; 
        int minIndex = -1;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            count = 0;
            for(int j=0; j<m; j++)
            {
                if(a[i][j]==1)
                    count++;
            }
            if(count<minCount)
            {
                minCount = count;
                minIndex = i+1;
            }
        }
        return minIndex;
    }
};
