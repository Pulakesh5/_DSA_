class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        long long sum1=0, sum2=0;
        
        for(int i=0; i<n; i++)
            sum1+=a[i];
        for(int i=0; i<m; i++)
            sum2+=b[i];
        
        if(sum1==sum2)
            return 1;
        if((sum1+sum2)%2)
            return -1;
            
        sort(a, a+n);
        sort(b, b+m);
        
        if(sum1>sum2)
        {
            swap(a,b);
            swap(n,m);
            swap(sum1, sum2);
        }
        long long diff = (sum2-sum1)/2, target;
        // cout<<sum1<<" "<<sum2<<" "<<diff<<endl;
        
        for(int i=0; i<n; i++)
        {
            target = (a[i]+diff);
            bool present = binary_search(a, a+n, target);
            
            if(present)
                return 1;
        }
        return -1;
    }
    // 11, 15
};
