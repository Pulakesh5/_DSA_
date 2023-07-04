class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long product = 1ll;
        int subArrayCount = 0, i = 0, j = 0;
        while(i<n)
        {
            product*=a[i];
            while(j<=i && product>=k)
            {
                product/=a[j++];
            }
            subArrayCount += (i-j+1);
            i++;
        }
        return subArrayCount;
    }
};
