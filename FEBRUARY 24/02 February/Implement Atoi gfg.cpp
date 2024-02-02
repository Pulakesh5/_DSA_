class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        long integer = 0;
        int start = (s[0]=='-'?1:0);
        for(int i=start; i<s.size(); i++)
        {
            if(s[i]>='0' && s[i]<='9')
                integer = integer*10+(s[i]-'0');
            else
                return -1;
        }
        if(s[0]=='-')
            return -1*integer;
        return integer;
    }
};
