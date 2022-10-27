    void rec(int l, int r, int arr[])
    {
        if(l>r) return;
        if(l==r)
        {
            leaves.push_back(arr[l]);
            return;
        }
        int i;
        for(i=l+1;i<=r;i++)
        {
            if(arr[i]>arr[l]) break;
        }
        rec(l+1,i-1,arr);
        rec(i,r,arr);
    }
    
    vector<int> leafNodes(int arr[],int N) {
        // code here
        int l=0,r=N-1;
        rec(l,r,arr);
        return leaves;
    }
