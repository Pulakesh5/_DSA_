class Solution {
  public:
    int minimumInteger(int N, vector<int> &A) {
        // code here
long long  sum=0;
        int min=INT_MAX;
        for(int i=0;i<N;i++) {
        sum+=A[i];
        }
    for(int i=0;i<N;i++) {
        if(A[i]*(long)N>=sum) {
        if(A[i]<min) {
            min=A[i];
        }
        }
    }
    return (int)min;
    }
};
