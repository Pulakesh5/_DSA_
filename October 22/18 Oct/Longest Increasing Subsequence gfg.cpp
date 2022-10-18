    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> LIS(n,1);
       for(int j=1;j<n;j++)
       {
            for(int i=0;i<j;i++)
                if(a[j] > a[i] && LIS[j] < (LIS[i]+1))
                    LIS[j]=LIS[i]+1;
       }
       
       return *max_element(LIS.begin(),LIS.end());
    }
