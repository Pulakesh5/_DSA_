class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    bool check(int rs, int re, int cs, int ce)
    {
        return (rs<=re && cs<=ce);
    }
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        int rs = 0, re = n-1;
        int cs = 0, ce = m-1;
        
        vector<int> ans;
        
        for(int i=cs; i<=ce; i++)
            ans.push_back(matrix[rs][i]);
        rs++;
        if(!check(rs, re, cs, ce))
            return ans;
        for(int i=rs; i<=re; i++)
            ans.push_back(matrix[i][ce]);
        ce--;
        if(!check(rs, re, cs, ce))
            return ans;
        for(int i=ce; i>=cs; i--)
            ans.push_back(matrix[re][i]);
        re--;
        if(!check(rs, re, cs, ce))
            return ans;
        for(int i=re; i>=rs; i--)
            ans.push_back(matrix[i][cs]);
        cs++;
            
        return ans;
    }
};
