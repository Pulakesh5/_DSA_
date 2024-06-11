class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<bool> served(n,false);
        vector<pair<int,int>> pq(n);
        for(int i=0; i<n; i++)
        {
            pq[i] = {abs(arr[i]-brr[i]),i};
        }
        sort(pq.begin(),pq.end());
        long long totalTip = 0, ind=0;
        for(int i=n-1; i>=0; i--)
        {
            ind = pq[i].second;
            if(arr[ind]>=brr[ind])
            {
                if(x>0)
                {
                    totalTip += arr[ind];
                    x--;
                }
                else
                {
                    totalTip += brr[ind];
                    y--;
                }
            }
            else
            {
                if(y>0)
                {
                    totalTip += brr[ind];
                    y--;
                }
                else
                {
                    totalTip += arr[ind];
                    x--;
                }
            }
        }
        return totalTip;
    }
};
