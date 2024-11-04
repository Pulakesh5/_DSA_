class Solution {
public:
    string compressedString(string word) {
        size_t len = word.size();
        string compressed = "";
        for(int i=0; i<len; )
        {
            int j;
            for(j=i+1; j<len && (j-i)<9; j++)
            {
                if(word[j]!=word[i])
                    break;
            }
            compressed.push_back('0'+(j-i));
            compressed.push_back(word[i]);
            i = j;
        }
        return compressed;
    }
};
