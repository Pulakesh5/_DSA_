bool isAdditiveSequence(string str) {
        // Your code here
        int len = str.size(), num1=0, num2=0, num3=0;
        for(int i=0; i<(len-2); i++)
        {
            num1 = num1*10 + (str[i]-'0');
            num2 = 0;
            for(int j=i+1; j<(len-1); j++)
            {
                num2 = num2*10+(str[j]-'0');
                int k = j+1;
                num3 = 0;
                while(k<len)
                {
                    num3 = num3*10+(str[k]-'0');
                    // if(num1>20)
                        // cout<<num1<<" "<<num2<<" "<<num3<<endl;
                    if(num3==(num1+num2))
                    {
                        num1 = num2;
                        num2 = num3;
                        num3 = 0;
                    }
                    k++;
                }
                if(k==len && num3==0)
                    return true;
            }
        }
        
        return false;
    }
