class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> left(n,0), right(n,n), height(n,0);
        int maxArea = 0;
        int currLeft, currRight;
        for(int i=0; i<m; i++)
        {
            currLeft = 0;
            currRight = n;
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]=='1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]=='1')
                    left[j] = max(left[j], currLeft);
                else
                {
                    left[j] = 0;
                    currLeft = j+1;
                }
            }

            for(int j=n-1; j>=0; j--)
            {
                if(matrix[i][j]=='1')
                    right[j] = min(right[j], currRight);
                else
                {
                    right[j] = n;
                    currRight = j;
                }
            }

            for(int j=0; j<n; j++)
            {
                maxArea = max(maxArea, (right[j]-left[j])*height[j]);
            }
        }
        return maxArea;
    }
};
