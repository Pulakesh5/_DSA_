    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        map<int,int> mp; // {sum,pos}
        long long sum=0;
        mp[0]=-1;
        int lengthSubArray=0,len;
        
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(mp.find(sum-K)!=mp.end()){
                len=i-mp[sum-K];
                if(len>lengthSubArray)
                {
                    lengthSubArray=len;
                    //cout<<i<<" "<<" "<<mp[sum-K]<<" "<<len<<endl;   
                }
            }
            if(mp.find(sum)==mp.end())
                mp[sum]=i;
            //cout<<"{"<<i<<", "<<sum<<"}, ";
            //mp[sum]=min(i,mp[sum]);
        }
        //cout<<endl;
        return lengthSubArray;
    } 
