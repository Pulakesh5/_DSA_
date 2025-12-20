class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int nRows = strs.size(), nCols = strs[0].size();
        int nDeletion = 0;
        for(int j=0; j<nCols; j++)
        {
            for(int i=1; i<nRows; i++)
            {
                if(strs[i-1][j]>strs[i][j])
                {
                    nDeletion++;
                    break;
                }
            }
        }
        return nDeletion;
    }
};
