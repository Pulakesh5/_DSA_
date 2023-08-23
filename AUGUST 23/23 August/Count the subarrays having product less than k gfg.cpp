class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        vector<long long> arr(a.begin(), a.end());
        long long l=0, r=0, len, j, minus;
        long long prevMul = 1ll;
        long long count=0;
        
        while(l<=r && r<n) 
        {
            if(prevMul*arr[r]<k)
            {
                prevMul*=arr[r];
                r++;
            }
            else
            {
                len = (r-l);
                count+=(len*(len+1))/2;
                // cout<<count<<endl;
                prevMul*=arr[r];
                j = l;
                while(l<=r && prevMul>=k)
                    prevMul/=arr[l++];
                j = (l-j);
                minus = len-j;
                count-=(minus*(minus+1))/2;
                r++;
            }
            // cout<<l<<" "<<r<<" "<<count<<" "<<prevMul<<endl;
        }
        
        len = (r-l);
        count+=(len*(len+1))/2;
        
        return count;
    }
};
