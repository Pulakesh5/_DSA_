class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        
        vector<int> strength(m,0);
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                strength[i]+=mat[i][j];
            }
        }
        
        vector<vector<int>> strengths;
        for(int i=0; i<m; i++)
            strengths.push_back({strength[i],i});

        sort(strengths.begin(), strengths.end(), comp);
        
        vector<int> kWeakest;
        for(int i=0; i<k; i++)
            kWeakest.push_back(strengths[i][1]);
        
        return kWeakest;
    }
};
