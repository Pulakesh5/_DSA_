class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        vector<bool> present(26, false);
        int len = s.size();
        for(int i=0; i<len; i++)
        {
            if(isalpha(s[i]))
            {
                if(s[i]>='A' && s[i]<='Z')
                    present[s[i]-'A'] = true;
                else if(s[i]>='a' && s[i]<='z')
                    present[s[i]-'a'] = true;
                // cout<<s[i];
            }
        }
        // cout<<endl;
        for(int i=0; i<26; i++)
        {
            if(!present[i])
                return false;
        }
        return true;
    }

};
