    int minSubset(vector<int> &Arr,int N){
        sort(Arr.begin(), Arr.end());
        long long totalSum=0,sum=0;
        for(int i=0;i<N;i++)
            totalSum+=Arr[i];
        int i=N;
        while(i>=0 && (sum*2)<=totalSum)
        {
            i--;
            sum+=Arr[i];
        }
        return N-i;
    }
