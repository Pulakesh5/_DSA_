    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        long long maxAns=0;
        long long count_of_sidepair=0, minSide=INT_MAX, sidePair;
        
        for(int i=0;i<N;i++)
        {
            sidePair=(B[i]/2);
            count_of_sidepair+=sidePair;
            maxAns+=(sidePair*2*A[i]);
            if(sidePair)
                minSide=min(minSide,2ll*A[i]);
        }
        
        if(count_of_sidepair%2) maxAns-=minSide;
        
        return maxAns;
    }
