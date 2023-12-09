class Solution {
  public:
    int sumDigit(int num)
    {
        int digSum=0;
        while(num>0)
        {
            digSum+=(num%10);
            num/=10;
        }
        return digSum;
    }
    bool isPrime(int n)
    {
        if(n==1)
            return false;
        int lim = sqrt(n);
        for(int d=2; d<=lim; d++)
            if((n%d)==0)
                return false;
        return true;
    }
    int smithNum(int n) {
        // code here
        if(isPrime(n))
            return 0;
        // cout<<"passed\n"<<endl;
        int nDigitSum = sumDigit(n);
        int lim = sqrt(n);
        
        vector<bool> isPrime(n+5, true);
        
        isPrime[0] = false;
        isPrime[1] = false;
        
        for(int d=2; d<=lim; d++)
        {
            // cout<<d<<" "<<isPrime[d]<<", ";
            if(isPrime[d])
            {
                for(int next=d*d; next<=n; next+=d)
                    isPrime[next] = false;
            }
        }
        
        int factorSum=0, num, factorCount;
        for(int f=2; f<=n; f++)
        {
            if(isPrime[f])
            {
                factorCount = 0;
                num = n;
                while(num%f == 0)
                {
                    // cout<<f<<", ";
                    factorCount++;
                    num = num/f;
                }
                factorSum += factorCount*sumDigit(f);
            }
        }
        // cout<<isPrime[5]<<" "<<isPrime[197];
        // cout<<"\n"<<factorSum<<" "<<nDigitSum<<endl;
        return factorSum==nDigitSum;
    }
    // 985 => 22
    // 985 = 5*197
};
