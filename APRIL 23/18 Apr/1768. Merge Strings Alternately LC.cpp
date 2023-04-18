class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged="";
        int i1=0,i2=0;
        int len1=word1.size(), len2=word2.size();
        while(i1<len1 || i2<len2)
        {
            if(i1<len1)
            {
                merged.push_back(word1[i1++]);
            }
            if(i2<len2)
            {
                merged.push_back(word2[i2++]);
            }
        }
        return merged;
    }
};
