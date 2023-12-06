class Solution {
  public:
    int check(int n, int d)
    {
        int c=0;
        while(n)
        {
            if(n%10==d)
                c++;
            n/=10;
        }
        return c;
    }
    int countX(int L, int R, int X) {
        // code here
        int count=0;
        for(int i=L+1; i<R; i++)
        {
            count+=check(i,X);
        }
        return count;
    }
};
