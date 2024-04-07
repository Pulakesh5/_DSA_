class Solution {
public:
    bool checkValidString(string s) {
        int mx=0, mn=0;
        for(char ch:s)
        {
            if(ch=='(')
                mx++, mn++;
            else if(ch==')')
                mx--, mn = max(mn-1,0);
            else
                mx++, mn = max(mn-1, 0);
            if(mx<0)
                return false;
        }
        return (mn==0);
    }
};
