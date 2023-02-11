    int getMinimumDays(int N,string S, vector<int> &P) {
        int count=0;
        
        for(int i=1;i<N;i++)
            count+=(S[i]==S[i-1]);
        
        int days=0;
        for(int i:P)
        {
            if(count==0) return days;
            
            if(i==0 && S[i]==S[i+1])
                count--;
            else if(i==N-1 && S[i]==S[i-1])
                count--;
            else if(S[i]==S[i-1] && S[i]==S[i+1])
                count-=2;
            else if(S[i]==S[i-1] || S[i]==S[i+1])
                count--;
            S[i]='?';
            days++;
        }
        return days;
    }
