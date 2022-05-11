class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        if(sum>(9*n)) return "-1";
        string ans(n,'0');
        int i=0;
        
        while(sum){
            if(sum>=9)
            {
                ans[i++]='9';
                sum-=9;
            }
            else{
                ans[i++]=('0'+sum);
                sum=0;
            }
        }
        
        return ans;
    }
};
