class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        if(arr[0]>k)
            return k;
        k -= (arr[0]-1);
        // cout<<k<<endl;
        int N = arr.size();
        for(int i=1; i<N; i++)
        {
            if(arr[i] - arr[i-1] > k)
                return arr[i-1]+k;
            else
                k -= (arr[i]-arr[i-1]-1);
            // cout<<i<<" "<<k<<endl;
        }
        
        return arr[N-1]+k;
    }
};
