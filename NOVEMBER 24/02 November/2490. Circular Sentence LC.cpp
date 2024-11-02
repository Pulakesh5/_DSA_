class Solution {
public:
    bool isCircularSentence(string sentence) {
        string word;
        vector<string> words;
        stringstream ss(sentence);
        while(ss>>word)
        {
            words.push_back(word);
        }
        int wordCount = words.size();
        for(int i=1; i<wordCount; i++)
        {
            int prevLen = words[i-1].size();
            if(words[i][0] != words[i-1][prevLen-1])
                return false;
        }
        return sentence[0]==sentence.back();
    }
};
