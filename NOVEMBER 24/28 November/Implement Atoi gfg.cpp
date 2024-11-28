class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        long long num = 0, mx=(1ll<<31)-1, mn=-(1ll<<31);
        
        int startPos = 0;
        bool negative = false;
        // checking for leading sign
        if(s[startPos]=='-' || s[startPos]=='+')
        {
            negative = (s[startPos]=='-');
            startPos++;
        }
        // skipping leading zeroes and blankspaces
        while(s[startPos]!='\0' && (s[startPos]==' ' || s[startPos]=='0'))
            startPos++;
        // processing digits
        while(s[startPos] != '\0')
        {
            if(!(s[startPos]>='0' && s[startPos]<='9'))
                break;
            num = num*10ll+(s[startPos]-'0');
            startPos++;
        }
        if(negative)
            num*=-1ll;
            
        if(num>=mx)
            return mx;
        else if(num<=mn)
            return mn;
        return num;
    }
};
