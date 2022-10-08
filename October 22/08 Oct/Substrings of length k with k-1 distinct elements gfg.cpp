    int countOfSubstrings(string S, int K) {
        // code here
        int n=S.length();
        vector<int> window(26,0);
        for(int i=0;i<K;i++)
        {
            window[S[i]-'a']++;
        }
        int distinct=0,subString=0;
        for(int i=0;i<26;i++)
                distinct+=(window[i]>0);
                
        if(distinct==(K-1)) subString++;
        for(int i=K;i<n;i++)
        {
            window[S[i-K]-'a']--;
            window[S[i]-'a']++;
            distinct=0;
            for(int i=0;i<26;i++)
                distinct+=(window[i]>0);
            if(distinct==(K-1)) subString++;
        }
        
        return subString;
    }
