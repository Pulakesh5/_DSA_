    long long int minIncrements(vector<int> arr, int n) {
        // Code here
        long long ops=0,maxTill=0;
        
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<n;i++)
        {
            if(maxTill<arr[i])
                maxTill=arr[i];
            else
            {
                maxTill++;
                ops+=(maxTill-arr[i]);
            }
        }
        
        return ops;
    }
