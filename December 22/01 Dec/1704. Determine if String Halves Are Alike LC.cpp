class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> st={'a','e','i','o','u','A','E','I','O','U'};

        int count=0, n = s.size();

        for(int i=0;i<(n/2);i++)
        {
            if(st.count(s[i])>0)
            {
                count++;
            }
        }

        for(int i=n/2;i<n;i++)
        {
            if(st.count(s[i])>0)
            {
                count--;
            }
            if(count<0) return false;
        }

        if(count>0) return false;

        return true;
    }
};
