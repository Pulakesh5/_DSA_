    int bitMagic(int n, vector<int> &arr) {
        // code here
        int count = 0;
        int lOne = 0, rOne = 0; 
        for(int l=0,r=n-1; l<r; l++,r--)
        {
            if(arr[l]!=arr[r])
            {
                lOne+=arr[l];
                rOne+=arr[r];
            }
        }
        int mn = min(lOne, rOne);
        lOne -= mn;
        rOne -= mn;
        lOne=(lOne+1)/2;
        rOne=(rOne+1)/2;
        return lOne + rOne + mn;
    }
