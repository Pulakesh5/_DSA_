    int dominantPairs(int n,vector<int> &arr){
        // Code here
        sort(arr.begin(), arr.begin()+n/2);
        sort(arr.begin()+n/2, arr.end());
        long long dominantPairs=0;
        for(int j=n/2;j<n;j++)
        {
            dominantPairs+=((arr.begin()+n/2)-lower_bound(arr.begin(), arr.begin()+n/2, 5*arr[j]));
        }
        return dominantPairs;
    }  
