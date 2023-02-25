int checkCompressed(string S, string T) {
        // code here
        //if(S.size()<T.size()) return 0;
        int i=0,j=0,lens=S.size(), lent=T.size();
        int count=0;
        while(i<lens && j<lent)
        {
            if(S[i]==T[j])
            {
                i++;
                j++;
                continue;
            }
            if((T[j]-'0')==0)
            {
                j++;
                continue;
            }
            
            count = 0;
            while(j<lent && isdigit(T[j]))
            {
                count = count*10 + (T[j]-'0');
                j++;
            }
            i+=count;
            //cout<<i<<" "<<j<<count<<endl;
            if(count==0) return 0;
        }
        
        return (i==lens && j==lent);
    }
