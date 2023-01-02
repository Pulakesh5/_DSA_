class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap=-1,sml=-1,i=0;
        for(char ch:word)
        {
            if(ch>='A' && ch<='Z')
                cap=i++;
            else
                sml=i++;
        }

        if(cap==-1 || sml==-1 || cap==0)
            return true;
        
        return false;

    }
};
