class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        // code here
        // i-th element is used (i+1)*(n-i) times 
        if(N%2==0)
            return 0;
        int xorOfAllSubarray=0;
        for(long long i=0; i<N; i++)
        {
            if(((i+1)*(N-i))%2==1)
                xorOfAllSubarray^=A[i];    
        }
            
        return xorOfAllSubarray;
    }
    
    // 1  2  3  4  5
    // 5  8  9  6  5
    // {1}^{1^2}^{1^2^3}^{2}^{2^3}^{3}
    // 1, 11, 00
    // 01
    // 11
    // 01
    // 00
    // 10
    // 11
};
