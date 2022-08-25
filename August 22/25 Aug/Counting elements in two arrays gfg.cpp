    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
    {
        vector<int> ans(m);
        sort(arr2,arr2+n);
        for(int i=0;i<m;i++){
            int count = upper_bound(arr2, arr2+n, arr1[i]) - arr2;
            ans[i]=count;
        }
        return ans;
    }
