string findSum(string X, string Y) {
        // Your code goes here
        int carry=0;
        int nx=X.size(), ny=Y.size();
        string sum="";
        int i=nx-1,j=ny-1,s;

        for(i;i>=0 && j>=0;i--,j--)
        {
            s=(X[i]-'0'+Y[j]-'0'+carry);
            sum += ((s%10)+'0');
            carry=s/10;
        }
           
        while(i>=0)
        {
            s=(X[i]-'0'+carry);
            sum += ((s%10)+'0');
            carry=s/10;
            i--;
        }
        
        while(j>=0)
        {
            s=(Y[j]-'0'+carry);
            sum += ((s%10)+'0');
            carry=s/10;
            j--;
        }
        
        if(carry>0)
        {
            sum+=(carry+'0');
        }
        while(sum.back()=='0')
            sum.pop_back();
            
        reverse(sum.begin(),sum.end());
        
        if(sum.size()==0) sum="0";
        return sum;
    }
