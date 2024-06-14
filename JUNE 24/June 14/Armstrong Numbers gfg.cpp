class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        int digit1 = n/100, digit2 = (n/10)%10, digit3 = n%10;
        digit1 = pow(digit1,3);
        digit2 = pow(digit2,3);
        digit3 = pow(digit3,3);
        int sum = digit1+digit2+digit3;
        // cout<<sum<<' '<<n<<endl;
        if(sum==n)
            return "true";
        else
            return "false";
    }
};
