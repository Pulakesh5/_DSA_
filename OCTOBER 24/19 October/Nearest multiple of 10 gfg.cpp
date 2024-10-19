class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int len = str.size();
        if(str.back()<='5')
        {
            str[len-1] = '0';
            return str;
        }
        
        str[len-1] = '0';
        int carry = 1;
        for(int i=len-2; i>=0; i--) {
            if(str[i]<'9')
            {
                str[i]++;
                carry = 0;
                break;
            }
            str[i] = '0';
        }
        
        if(carry)
            str = "1"+str;
        return str;
        
    }
};
