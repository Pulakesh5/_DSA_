class Solution
{
    public:
    int countFractions(int n, int num[], int denom[])
    {
        int  gcd;
        map<pair<int,int>, int> fractions;
        for(int i=0; i<n; i++)
        {
            gcd = __gcd(num[i], denom[i]);
            fractions[{num[i]/gcd, denom[i]/gcd}]++;
        }
        // sort(fractions.begin(), fractions.end());
        long long count = 0;
        
        for(auto fraction:fractions)
        {
            auto x = fraction.first;
            auto reciprocal = make_pair((x.second-x.first),x.second);
            int c = fraction.second;
            
            if(x.second!=2ll)
            {
                count+= (c*fractions[reciprocal]);
                fractions[x] = 0;
            }
        }
        
        int y = fractions[{1,2}];
        count+=(y*(y-1))/2;
        
        return count;
        
        
    }
};
