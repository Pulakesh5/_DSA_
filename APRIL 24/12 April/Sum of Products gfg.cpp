class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        vector<int> count(32,0);
        int num, pos;
        for(int i=0; i<n; i++)
        {
            num = arr[i];
            pos = 0;
            while(num)
            {
                if(num%2)
                    count[pos]++;
                num/=2;
                pos++;
            }
        }
        
        long long pair_And_Sum = 0;
        for(int i=0; i<n; i++)
        {
            num = arr[i];
            pos = 0;
            while(num)
            {
                if(num%2)
                {
                    pair_And_Sum += (1ll<<pos)*(count[pos]-1);
                }
                num/=2;
                pos++;
            }
        }
        
        return pair_And_Sum/2;
        /*
        5  => 0101
        10 => 1010
        15 => 1111
        */
    }
};
