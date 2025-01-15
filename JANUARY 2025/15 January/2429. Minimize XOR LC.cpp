class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setbitnum2 = __builtin_popcount(num2);
        int msbnum1 = 31 - __builtin_clz(num1);
        long long target = 0;
        while(setbitnum2 && msbnum1>=0)
        {
            if(num1&(1<<msbnum1))
            {
                target = target | (1ll<<msbnum1);
                // cout<<"bit matched at "<<msbnum1<<endl;
                setbitnum2--;
            }
            msbnum1--;
        }
        
        // cout<<"set bit count of num2 "<<setbitnum2<<endl;
        // cout<<"msb of num1 "<<msbnum1<<endl;
        // cout<<31 - __builtin_clz(num1)<<endl;
        // cout<<31 - __builtin_clz(num2)<<endl;
        int pos=0;
        while(setbitnum2>0)
        {
            if(!(num1&(1ll<<pos)))
            {
                target = target | (1ll<<pos);
                // cout<<"bit matched at "<<msbnum1<<" "<<target<<endl;
                setbitnum2--;
            }
            pos++;
        }
        return target;
        // cout<<setbitnum2<<endl;
        // return -1;
    }
};
