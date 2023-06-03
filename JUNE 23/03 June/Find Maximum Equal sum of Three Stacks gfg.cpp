    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        vector<int> suf1(N1+1), suf2(N2+1), suf3(N3+1);
        suf1[N1]=0;
        long long Sum1 = 0, Sum2=0, Sum3=0;
        for(int i=N1-1; i>=0; i--)
            Sum1+=S1[i];

        for(int i=N2-1; i>=0; i--)
            Sum2+=S2[i];
        
        for(int i=N3-1; i>=0; i--)
            Sum3+=S3[i];
        int top1= 0, top2=0, top3=0;
        while(top1<N1 && top2<N2 && top3<N3)
        {
            if(Sum1==Sum2 && Sum2==Sum3)
                return Sum1;
            while(top1<N1 && Sum1>min(Sum2,Sum3))
            {
                Sum1-=S1[top1++];
            }
            while(top2<N2 && Sum2>min(Sum1,Sum3))
            {
                Sum2-=S2[top2++];
            }
            while(top3<N3 && Sum3>min(Sum1,Sum2))
            {
                Sum3-=S3[top3++];
            }
        }
        return 0;
    }
