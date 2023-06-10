class Solution {
public:
    bool check(long long mid, long long ind, long long maxSum, int n)
    {
        long long ans = sum(mid-1, ind) + sum(mid, n - ind);
        return ans <= maxSum;
    }
    long long sum(long long a, int n)
    {
        long  an = 0, extras = 0;
        long long ans = 0;
        if(n>=a)
        {
            an = 1;
            extras = (n-a);
        }
        else if(n<a)
        {
            extras = 0;
            an = a - n + 1;
        }
        ans = ((an+a) * (a-an+1))/2;
        ans += extras;
        return ans;
    }
    int maxValue(int n, int index, int maxSum) {
        if(n==1) return maxSum;
        if(n==2) return (maxSum+1)/2;
        long long low = 1, high = maxSum, mid;
        int max_at_index = 1;
        
        while(low<=high)
        {
            mid = (low+high)/2;
            // cout<<mid<<" : ";
            if(check(mid, index, maxSum, n))
            {
                max_at_index = mid;
                // cout<<"returned true\n";
                low = mid + 1;
            }
            else
            {
                // cout<<"returned false\n";
                high = mid - 1;
            }
        }
        return max_at_index;
    }
};

