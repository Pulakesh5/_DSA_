class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        string next = "";
        while(r--)
        {
            int len = s.size();
            
            for(int i=0; i<len && next.size()<=n; i++)
            {
                if(s[i]=='0')
                {
                    next.push_back('0');
                    next.push_back('1');
                }
                else
                {
                    next.push_back('1');
                    next.push_back('0');
                }
            }
            s = next;
            next = "";
        }
        return s[n];
    }
};
