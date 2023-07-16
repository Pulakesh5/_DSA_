class Solution {
public:
    int backtrack(vector<long long> &numRows, int &c, long long index, int numSelect, long long mask)
    {

        if(numSelect==0 || index==c)
        {
            int count = 0;
            for(int i=0; i<numRows.size(); i++)
                if((numRows[i]&mask)==numRows[i])
                    count++;
            // cout<<index<<" "<<numSelect<<" "<<mask<<" : "<<count<<endl;
            return count;
        }
        // cout<<"called with "<<index<<" "<<numSelect<<" "<<mask<<endl;
        int set = backtrack(numRows, c, index+1, numSelect-1, (mask | (1ll<<index)));
        int notSet = backtrack(numRows, c, index+1, numSelect, mask);
        // cout<<index<<" : "<<set<<" "<<notSet<<endl;
        return max(set, notSet);
    }
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        vector<long long> rowNums;
        int r = matrix.size(), c = matrix[0].size();
        long long rowNum;
        for(vector<int> row:matrix)
        {
            rowNum = 0ll;
            for(int i=0; i<c; i++)
            {
                if(row[i]==1)
                    rowNum = (rowNum | (1ll<<i));
            }
            rowNums.push_back(rowNum);
            // cout<<rowNum<<endl;
        }
        long long index = 0, mask = 0ll;
        return backtrack(rowNums, c, index, numSelect, mask);
    }
};
