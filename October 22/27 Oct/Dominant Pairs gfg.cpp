    int dominantPairs(int n,vector<int> &arr){
        // Code here
        vector<int>a;
        vector<int>b;
        for(int i=0;i<n/2;i++)
        {
            a.push_back(arr[i]);
        }
         for(int i=n/2;i<n;i++)
        {
            b.push_back(5*arr[i]);
        }
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        
        int i=0;
        int j=0;
        int m=n/2;
        int c=0;
        
        for(int i=0;i<a.size();i++)
        {
            int ub=upper_bound(b.begin(),b.end(),a[i])-b.begin();
            c+=ub;
        }
        
        return c;
    }  
