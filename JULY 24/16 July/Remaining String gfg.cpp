class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        int i, len = s.size();
        for(i=0; i<len && count; i++)
        {
            if(s[i]==ch)
            {
                count--;
            }
        }
        if(i==len || count)
            return "";
        return s.substr(i);
    }
};
