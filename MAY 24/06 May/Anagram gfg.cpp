class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        vector<int> count(26,0);
        for(char ch:a)
            count[ch-'a']++;
        for(char ch:b)
            count[ch-'a']--;
        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return false;
        }
        return true;
    }

};
