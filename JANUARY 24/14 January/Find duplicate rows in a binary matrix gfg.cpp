class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        set<vector<int>> rows;
        rows.insert(matrix[0]);
        vector<int> duplicateRows;
        
        for(int i=1; i<M; i++)
        {
            if(rows.find(matrix[i])==rows.end())    
                rows.insert(matrix[i]);
            else
                duplicateRows.push_back(i);
        }
        return duplicateRows;
    } 
};
