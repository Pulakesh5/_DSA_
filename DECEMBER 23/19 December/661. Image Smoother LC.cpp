class Solution {
public:
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    int row, col;
    int smoothe(vector<vector<int>> &image, int i, int j)
    {
        int ni, nj, cnt=1, avg=image[i][j];
        // cout<<"called with "<<i<<" "<<j<<endl;
        for(int k=0; k<8; k++)
        {
            ni = i+dx[k];
            nj = j+dy[k];
            if(ni>-1 && nj>-1 && ni<row && nj<col)
            {
                cnt++;
                avg+=image[ni][nj];
            }
        }
        return avg/cnt;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(), m=img[0].size();
        row = n;
        col = m;
        vector<vector<int>> smoothedImage(n,vector<int>(m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                smoothedImage[i][j] = smoothe(img,i,j);
            }
        }
        return smoothedImage;
    }
};
