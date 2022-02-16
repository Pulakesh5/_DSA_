class Solution{
    public:
    bool ValidCorner(const vector<vector<int> >& matrix)
    {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> ones(n);
        //store ones of each row
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]) ones[i].push_back(j);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int> vec(200);
                // calculating intersection of two rows of ones  
                auto it=set_intersection(ones[i].begin(), ones[i].end(),
                                         ones[j].begin(), ones[j].end(), vec.begin());
                //if there are >= 2 intersection points then answer is true
                if(it-vec.begin() >=2)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
