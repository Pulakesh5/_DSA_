class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            // your code here
            int maxOne = 0, maxOneRow = -1, oneCount = 0;
            for(int i=0; i<N; i++) {
                oneCount = 0;
                for(int j=0; j<M; j++) {
                    oneCount += Mat[i][j];
                }
                if(oneCount>maxOne) {
                    maxOne = oneCount;
                    maxOneRow = i;
                }
            }
            return maxOneRow;
        }
};
