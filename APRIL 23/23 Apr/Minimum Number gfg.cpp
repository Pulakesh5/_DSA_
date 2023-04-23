    int minimumNumber(int n,vector<int> &arr){
        int gcd=arr[0];
        for(int i=1;i<n;i++)
            gcd = __gcd(arr[i],gcd);
        return gcd;
    }
