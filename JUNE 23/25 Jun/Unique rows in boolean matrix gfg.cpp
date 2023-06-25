class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        unordered_set<long long> uniqueNums;
        vector<int> vec;
        int pos = 0;
        long long powerOfTwo = 1, num;
        vector<vector<int>> rows;
        for(int i=0; i<row; i++)
        {
            num = 0;
            powerOfTwo = 1;
            vec.clear();
            for(int j=0; j<col; j++)
            {
                vec.push_back(M[i][j]);
                if(M[i][j]==1)
                    num+=powerOfTwo;
                powerOfTwo<<=1;
            }
            if(uniqueNums.find(num)==uniqueNums.end())
            {
                rows.push_back(vec);
                uniqueNums.insert(num);
            }
        }
        return rows;
    }
};
