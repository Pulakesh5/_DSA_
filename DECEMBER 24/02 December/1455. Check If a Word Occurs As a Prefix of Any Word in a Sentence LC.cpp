class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        size_t N_word = searchWord.size(), N_sentence = sentence.size();
        stringstream ss(sentence);
        string word;
        int wordIndex = 0;
        while(ss>>word)
        {
            wordIndex++;
            if(word[0]!=searchWord[0])
                continue;
            if(searchWord == word.substr(0, N_word))
                return wordIndex;
        }
        return -1;
    }
};
