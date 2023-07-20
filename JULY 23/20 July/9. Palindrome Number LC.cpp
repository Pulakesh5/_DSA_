class Solution {
public:
    bool isPal(string s)
    {
        int r = s.size()-1, l=0;
        while(l<r)
        {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        string s;
        while(x)
        {
            s.push_back('0'+(x%10));
            x/=10;
        }
        return isPal(s);
    }
};
