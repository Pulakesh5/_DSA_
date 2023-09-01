class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0)
            return {0};
        if(n==1)
            return {0,1};
        vector<int> bits(n+1);
        bits[0] = 0;
        bits[1] = 1;
        bits[2] = 1;
        int now=1,next, num=3;
        while(num<=n)
        {
            next=2*now;
            bits[now] = 1;
            for(num=now+1; num<next && num<=n; num++)
                bits[num] = 1+bits[num-now];
            now = next;
        }
        return bits;
    }
};
