class Solution {
public:
    bool detectCapitalUse(string word) {
        int i=0, n=word.size();
        bool flag1=true,flag2=true,flag3=true;
        for(int i=0;i<n && flag1;i++){
            if(word[i]<'A' || word[i]>'Z')
                flag1=false;
        }
        for(int i=0;i<n && flag2;i++){
            if(word[i]<'a' || word[i]>'z')
                flag2=false;
        }
        flag3 = (word[0]>='A' && word[0]<='Z');
        for(int i=1;i<n && flag3;i++){
            if(word[i]<'a' || word[i]>'z')
                flag3=false;
        }
        return flag1|| flag2||flag3;
        
    }
};

//

class Solution {
public:
    bool detectCapitalUse(string word) {
        int i=0, n=word.size();
        for(int i=1;i<n;i++){
            if(isupper(word[1]) != isupper(word[i]) || islower(word[0]) && isupper(word[i]))
                return false;
        }
        return true;
    }
};
