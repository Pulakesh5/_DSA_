class Solution {
public:
    const long long MOD = 1e9+7;

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int lim = *max_element(nums.begin(), nums.end())+5;
        vector<int> prime_score(lim);
        vector<bool> isPrime(lim, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int num=2; num<lim; num++) {
            if(!isPrime[num])
                continue;
            for(int next=num; next<lim; next+=num)
            {
                isPrime[next] = false;
                prime_score[next]++;
            }
        }

        vector<int> left(n), right(n);
        stack<int> stk;
        for(int i=0; i<n; i++) {
            while(!stk.empty() && prime_score[nums[i]]>prime_score[nums[stk.top()]])
                stk.pop();
            left[i] = (stk.empty() ? -1: stk.top());
            stk.push(i);
        }
        stk = stack<int>();
        for(int i=n-1; i>=0; i--) {
            while(!stk.empty() && prime_score[nums[i]]>=prime_score[nums[stk.top()]])
                stk.pop();
            right[i] = (stk.empty()? n:stk.top());
            stk.push(i);
        }

        vector<pair<int,int>> vp(n);
        for(int i=0; i<n; i++)
            vp[i] = {nums[i], i};
        
        sort(vp.rbegin(), vp.rend());

        long long ans = 1;
        
        for(const auto& [num, ind]:vp) {
            long long op = min(1ll*(ind-left[ind])*(right[ind]-ind), 1ll*k);
            // cout<<num<<" ind = "<<ind<<" l = "<<left[ind]<<" r= "<<right[ind]<<endl;
            ans = (ans*pow(num, op))%MOD;
            // cout<<op<<" "<<ans<<endl;
            cout<<pow(num,op)<<endl;
            k -= op;
            if(k==0)
                return ans;
        }
        return ans;
    }

    long long pow(long x, long n) {
        long long ans = 1;
        while(n>0) {
            if(n&1)
                ans = (1ll*ans*x)%MOD;
            x = (x*x)%MOD;
            n/=2;
        }
        return ans;
    }

};
