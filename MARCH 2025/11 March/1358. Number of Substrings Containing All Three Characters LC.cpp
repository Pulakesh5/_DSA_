class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0, b=0, c=0;
        int subString = 0, N = s.size();
        for(int left=0, right=0; right<N; right++)
        {
            if(s[right]=='a')
                a++;
            else if(s[right]=='b')
                b++;
            else
                c++;
            while(a && b && c)
            {
                if(s[left]=='a')
                    a--;
                else if(s[left]=='b')
                    b--;
                else
                    c--;
                left++;
            }
            subString+=left;
        }
        return subString;
    }
};
