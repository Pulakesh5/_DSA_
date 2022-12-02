int isItPossible(string S, string T, int M, int N) {
        // code here
        if(M!=N) return 0;
        
        int i=0, j=0;
        
        for(i=0;i<N && j<N;)
        {
            while(i<N && S[i]=='#') i++;
            while(j<N && T[j]=='#') j++;
            if(S[i]!=T[j]) return 0;
            if(T[j]=='A' && i<j) return 0;
            if(T[j]=='B' && i>j) return 0;
            i++;
            j++;
        }
        while(i<N){
            if(S[i]!='#') return 0;
            i++;
        }
        while(j<N){
            if(T[j]!='#') return 0;
            j++;
        }
        return 1;
    }
