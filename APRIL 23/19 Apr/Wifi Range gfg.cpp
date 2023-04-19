    bool wifiRange(int N, string S, int X){
        int prev1=-1;
        for(int i=0;i<N;i++)
        {
            if(S[i]=='1')
            {
                if(prev1==-1 && i>X) // starting 0's
                    return false;
                    
                if((i-prev1-1)>2*X) // In between 0's
                    return false;
                prev1=i;
            }
        }
        if(N-1-prev1>X)
            return false;
        return true;
    }
