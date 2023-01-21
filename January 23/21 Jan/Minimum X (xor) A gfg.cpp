    int minVal(int a, int b) {
        // code here
        int count_b=0;
        while(b)
        {
            if(b&1) count_b++;
                b=b>>1;
        }
        
        long long X=0;
        int pos=32;
        
        while(pos>=0 && count_b)
        {
            if((1ll<<pos)&a)
            {
                count_b--;
                X+=(1ll<<pos);
            }
            pos--;
        }
        
        pos=0;
        
        while(pos<=32 && count_b)
        {
            if(!(1ll<<pos &a))
            {
                count_b--;
                X+=(1ll<<pos);
            }
            pos++;
        }
        
        return X;
    }
