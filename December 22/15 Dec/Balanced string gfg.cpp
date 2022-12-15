    int SumOfDigit(int N)
    {
        int sum=0;
        while(N)
        {
            sum+=(N%10);
            N/=10;
        }
        return sum;
    }
    string BalancedString(int N) {
        // code here
        string alphabet="abcdefghijklmnopqrstuvwxyz";
        string balancedString="";
        
        for(int c=0;c<(N/26);c++)
        {
            for(int i=0;i<26;i++)
                balancedString.push_back(alphabet[i]);
        }
        
        int sod=SumOfDigit(N);
        N%=26;
        int count = (N >> 1) + (N & 1) * (1 - (sod & 1));
        
        balancedString += alphabet.substr(0, count);
        balancedString += alphabet.substr(26 - N + count, count + 1);
        
        return  balancedString;
    }
