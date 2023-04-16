class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // code here
        long long sumA=0, sumB=0;
        // map<int,int> freqA, freqB;
        int oddA=0,evenA=0,oddB=0,evenB=0;
        vector<int> AEvenOdd[2], BEvenOdd[2];
        for(int i=0;i<N;i++)
        {
            sumA+=A[i];
            sumB+=B[i];
            if(A[i]%2==0)
                AEvenOdd[0].push_back(A[i]);
            else
                AEvenOdd[1].push_back(A[i]);
            if(B[i]%2==0)
                BEvenOdd[0].push_back(B[i]);
            else
                BEvenOdd[1].push_back(B[i]);
        }
        if(sumA!=sumB || AEvenOdd[0].size()!=BEvenOdd[0].size())
            return -1;
        long long ans=0;
        for(int i=0;i<2;i++)
        {
            sort(AEvenOdd[i].begin(),AEvenOdd[i].end());
            sort(BEvenOdd[i].begin(),BEvenOdd[i].end());
            for(int j=0;j<AEvenOdd[i].size();j++)
            {
                ans+= abs(AEvenOdd[i][j]-BEvenOdd[i][j])/2;
            }
        }
        return ans/2;
    }
};
