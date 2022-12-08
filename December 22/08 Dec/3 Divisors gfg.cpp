    void prime(long long N, vector<long long> &v)
    {

        vector<int> nums(N+5,1);
        for(int i=2;i*i<=N;i++)
        {
            if(nums[i]==1)
            {
                v.push_back(i);
                for(int j=i*i;j<=N;j+=i)
                    nums[j]=0;
            }
        }
    }
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> ans(q,0);
        vector<long long> primes;
        long long N = *max_element(query.begin(),query.end());
        
        prime(N,primes);
        
        int n=primes.size();
        
        for(int i=0;i<n;i++) primes[i]=(primes[i]*primes[i]);
        
        //cout<<"n : "<<n<<endl;
        for(int i=0;i<q;i++)
        {
            auto it=lower_bound(primes.begin(), primes.end(),sqrt(query[i]))-primes.begin();
            int count=0;//check=sqrt(query[i]);
            for(int j=0;j<n;j++)
            {
                if(primes[j]<=query[i])
                count++;
                else
                break;
            }
            ans[i]=count;
        }
        return ans;
    }
