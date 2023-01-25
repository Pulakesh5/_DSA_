    int minOperation(string str) {
        // code here
        int n=str.size(), op=0;
        bool flag = true;
        for(int i=n-1;i>=0;i--)
        {
            if(i&1)
            {
                flag = true;
                for(int f=0,s=(i+1)/2;s<=i && flag;f++,s++)
                {
                    if(str[f]!=str[s])
                        flag = false;
                }
                if(flag) 
                    return (op+(i+1)/2+1);
                
            }
            
            op++;
            
            //cout<<i<<" "<<op<<endl;
        }
        return op;
    }
