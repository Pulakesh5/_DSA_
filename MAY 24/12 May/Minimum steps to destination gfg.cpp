class Solution {
  public:
    int minSteps(int d) {
        // code here
        for(long long i=1; i<=(2*d); i++)
        {
            long long sum = (i*(i+1))/2;
            if((sum+d)%2==0 && sum>=d)
                return i;
        }
        return 2*d;
    }
};
