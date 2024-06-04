class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int i = s.size()-1;
        while(i>=0)
        {
            if(s[i]=='0')
            {
                s[i] = '1';
                break;
            }
            s[i] = '0';
            i--;
        }
        if(i>=0)
        {
            int i=0;
            while(i<s.size() && s[i]=='0')
                i++;

            return s.substr(i);
        }
        s = "1"+s;
        return s;
    }
};
