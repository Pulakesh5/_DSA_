class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<64> bitn(n-1), bitx(x);
        long long minPossibleNum = 0;
        int j=0;
        // cout<<bitn.to_string()<<"\n"<<bitx.to_string()<<endl;
        for(size_t i=0; i<bitn.size(); i++)
        {
            if(bitx.test(i))
            {
                minPossibleNum += (1ll<<i);
                continue;
            }
            // cout<<i<<" "<<j<<" : "<<bitn.test(j)<<endl;
            if(bitn.test(j))
                minPossibleNum += (1ll<<i);
            j++;
        }
        return minPossibleNum;
    }
    // 11
    // 100
};
