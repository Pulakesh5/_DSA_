class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int n=t.length();
        for(int i=0;i<n;i++){
            if(s[i]!=t[i])
                return t[i];
        }
        return t[n-1];
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch=0;
        for(auto c:s) ch^=c;
        for(auto c:t) ch^=c;
        return ch;
    }
};
