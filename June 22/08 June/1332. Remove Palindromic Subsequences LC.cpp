class Solution {
public:
    bool ispal(string s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        return ispal(s,0,s.length()-1) ? 1:2;
    }
};
