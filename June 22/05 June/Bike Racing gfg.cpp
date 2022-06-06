class Solution{
public:
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        long low=0,high=max(M,L);
        long ans=0,mid=0;
        while(low<=high){
            mid=(low+high)/2;
            long fast=0;
            for(int i=0;i<N;i++){
                if(H[i]+A[i]*mid >= L)
                    fast+=(H[i]+A[i]*mid);
            }
            if(fast>=M){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};
