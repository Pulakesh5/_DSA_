class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)
            return {1};
        else if(rowIndex==1)
            return {1,1};
        vector<int> curRow(rowIndex+1,1), prevRow(rowIndex+1, 1);

        for(int i=2; i<=rowIndex; i++)
        {
            // curRow[1]=prevRow[0]+prevRow[1];
            for(int j=1; j<i; j++)
            {
                curRow[j]=(prevRow[j-1]+prevRow[j]);
            }
            prevRow = curRow;
        }
        return curRow;
    }
};
