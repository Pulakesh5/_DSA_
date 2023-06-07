class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32> bs_a(a), bs_b(b), bs_c(c);
        int count=0;
        for(int i=0;i<32;i++)
        {
            if(bs_a[i]==bs_b[i] && bs_a[i]==0 && bs_c[i]==0)
                continue;
            if(bs_a[i]!=bs_b[i])
                count+=(bs_c[i]==0);
            if(bs_a[i]==bs_b[i] && bs_a[i]==0 && bs_c[i]==1)
                count++;
            else if(bs_a[i]==bs_b[i] && bs_a[i]==1 && bs_c[i]==0)
                count+=2;
        }
        return count;
    }
};
