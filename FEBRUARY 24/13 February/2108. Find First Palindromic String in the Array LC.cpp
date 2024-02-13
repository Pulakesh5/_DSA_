class Solution {
public:
    bool isPalindrome(string str)
    {
        int l=0, r=str.size()-1;
        while(l<r)
        {
            if(str[l]!=str[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(string word:words)
        {
            if(isPalindrome(word))
                return word;
        }
        return "";
    }
};
