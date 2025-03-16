class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n<=1)
            return 0;
        int thisRange = 0, nextRange = 0;
        int index=0, jump=0;
        while(index<=thisRange)
        {
            for(;index<=thisRange; index++)
            {
                if(nextRange<(index+arr[index]))
                    nextRange = (index+arr[index]);
                if(nextRange>=(n-1))
                    return jump+1;
            }
            thisRange = nextRange;
            jump++;
        }
        return -1;
    }
};
