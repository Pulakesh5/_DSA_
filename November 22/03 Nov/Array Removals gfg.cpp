class Solution{
    public:
    int removals(vector<int>& arr, int k){
        //Code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int l=0,r=n-1;
        
        int minRemoval=n;
        for(int i=0;i<n;i++)
        {
            int ul=lower_bound(arr.begin(), arr.end(), arr[i]+k+1)-arr.begin();
            minRemoval=min(minRemoval,n-ul+i);
        }
        
        return minRemoval;
    }
};
