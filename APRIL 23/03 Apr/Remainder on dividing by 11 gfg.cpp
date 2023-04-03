    int xmod11(string number)
    {
        string dividend;
        int idx = 0;
        int temp = number[idx] - '0';
        int len = number.size();
        
        while(temp<11 && idx<len)
        {
            //cout<<idx<<" "<<temp<<" ";
            temp = temp*10 + (number[++idx]-'0');
            //cout<<temp<<endl;
        }
        
        while(idx+1<len)
        {
            //dividend+= (temp/11)+'0';
            temp = (temp%11)*10 + number[++idx]-'0';
            //cout<<idx<<" "<<temp<<endl;
        }
        return temp%11;
    }
