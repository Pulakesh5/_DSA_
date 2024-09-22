class Solution {
public:
    int findKthNumber(int n, int k) {
        int ans = 1;
        k--;
        while(k)
        {
            int count = 0;
            for(long long first=ans, last=first+1; first<=n; first*=10, last*=10)
            {
                count += (min(1ll+n, last) - first);
            }

            if(k >= count)
            {
                k -= count;
                ++ans;
            }
            else
            {
                ans *= 10;
                k--;
            }
        }
        return ans;
    }
};
