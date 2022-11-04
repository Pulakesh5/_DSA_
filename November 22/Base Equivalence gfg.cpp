    int digitCount(int num, int base)
    {
        int count=0;
        while(num)
        {
            count++;
            num/=base;
        }
        return count;
    }
    string baseEquiv(int n, int m){
        // code here
        for(int base=2;base<=32;base++)
        {
            if(digitCount(n,base)==m)
                return "Yes";
        }
        return "No";
    }
