class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        if(str1.size() != str2.size())
            return false;
            
        map<char, char> mp12, mp21;
        
        for(int i=0; i<26; i++)
        {
            mp12['a'+i] = '$';
            mp21['a'+i] = '$';
        }
        int len1 = str1.size();
        for(int i=0; i<len1; i++)
        {
            if(mp12[str1[i]]=='$' && mp21[str2[i]]=='$')
            {
                mp12[str1[i]] = str2[i];
                mp21[str2[i]] = str1[i];
            }
            else if(mp12[str1[i]]==str2[i] && mp21[str2[i]]==str1[i])
                continue;
            else
                return false;
        }
        
        return true;
        
    }
};
