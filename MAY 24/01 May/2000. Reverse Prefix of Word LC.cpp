class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = -1;
        int len = word.size();
        for(int i=0; i<len; i++)
        {
            if(word[i]==ch)
            {
                if(index==-1)
                    index=i;
                else
                    break;
            }
        }
        if(index==-1)
            return word;
        reverse(word.begin(), word.begin()+index+1);
        return word;
    }
};
