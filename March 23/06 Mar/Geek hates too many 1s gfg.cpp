    int noConseBits(int n) {
        int ans=0;
        int i=31;
        int count=0;
        while(i>=0)
        {
            if(count<=1 && (n&(1<<i)))
            {
                ans=(ans|(1<<i));
                count++;
            }
            else
            {
                count=0;
            }
            i--;
        }
        return ans;
    }
