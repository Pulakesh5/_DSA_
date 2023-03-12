    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        int row=-1, maxCount=-1;
        vector<int> ans;
        for(int i=0;i<N;i++)
        {
            int count = N - (lower_bound(mat[i].begin(), mat[i].end(), 1) - mat[i].begin());
            
            if(count>maxCount)
            {
                maxCount = count;
                ans = {i,maxCount};
            }
        }
        
        return ans;
    }
