    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> rv;
        int mx=-1,mxpos=-1;
        for(int i=0;i<k;i++)
        {
            if(arr[i]>mx)
            {
                mx=arr[i];
                mxpos=i;
            }
        }
        rv.push_back(arr[mxpos]);
        for(int l=1,r=k;r<n;l++,r++)
        {
            if(arr[r]>=mx)
            {
                mx=arr[r];
                mxpos=r;
            }
            if(mxpos<l)
            {
                mx=-1;
                for(int i=l;i<=r;i++)
                {
                    if(mx<arr[i])
                    {
                        mx=arr[i];
                        mxpos=i;
                    }
                }
            }
            rv.push_back(arr[mxpos]);
        }
        
        return rv; 
        
    }
