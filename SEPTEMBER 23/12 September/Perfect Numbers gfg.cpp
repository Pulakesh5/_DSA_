class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        double lim = sqrt(N);
        long long sum=0;
        for(int d=2; d<lim; d++)
        {
            if(N%d==0)
            {
                sum+=d;
                sum+=(N/d);
            }
        }
        sum++; //for factor = 1
        // cout<<sum<<" "<<lim<<endl;
        if(lim*lim==N)
            sum+=lim;
        return sum==N;
    }
};
