class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        // ylogx > xlogy
        int n = arr.size();
        int m = brr.size();
        vector<double> aux(m);
        for(int i=0; i<m; i++)
            aux[i] = (double)brr[i]/log2(brr[i]);
        
        sort(aux.begin(), aux.end());
        
        long long pairCount = 0;
        for(int x:arr)
        {
            double temp = (double)x/log2(x);
            int l=0, r=m-1;
            int validPairs=0;
            while(l<=r)
            {
                int mid = l+(r-l)/2;
                if(aux[mid]>temp)
                    r = mid-1;
                else
                {
                    l = mid+1;
                    validPairs = l;
                }
            }
            pairCount += (m-validPairs);
        }
        return pairCount;
    }
};
