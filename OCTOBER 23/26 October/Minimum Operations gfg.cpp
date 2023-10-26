class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        int ops = 0;
        while(n)
        {
            if(n&1)
                n--;
            else
                n/=2;
            ops++;
        }
        return ops;
        // cout<<log2(n)<<endl;
        // return 1+log2(n)+(n - (1<<(int)log2(n)));
    }
};
