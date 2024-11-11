class Solution {
public:
    void fillPrimes(set<int> &primes)
    {
        vector<bool> isPrime(1001, true);
        isPrime[1] = false;
        for(int p=2; p<=1000; p++)
        {
            if(isPrime[p])
            {
                for(int next=p*p; next<=1000; next+=p)
                {
                    isPrime[next] = false;
                }
            }
        }
        for(int i=2; i<=1000; i++)
        {
            if(isPrime[i])
                primes.insert(i);
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        // constant work
        set<int> primes;
        fillPrimes(primes);
        
        int curr = 1;
        int i=0; 
        size_t len = nums.size();
        while(i<len)
        {
            int diff = nums[i]-curr;
            if(diff<0)
                return false;
            
            if(primes.find(diff)!=primes.end() || diff == 0)
            {
                i++;
                curr++;
            }
            else
                curr++;
        }
        return true;
    }
};
