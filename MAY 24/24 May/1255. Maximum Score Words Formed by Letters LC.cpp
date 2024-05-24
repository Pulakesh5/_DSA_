class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int maxScoreOfWords = 0;
        vector<int> charFrequencyOfLetters(26,0);
        for(char ch:letters)
        {
            charFrequencyOfLetters[ch-'a']++;
        }

        for(int subset=1; subset<(1<<words.size()); subset++)
        {
            vector<int> charFrequency(26,0);
            for(int i=0; i<words.size(); i++)
            {
                if(subset&(1<<i))
                {
                    for(char ch:words[i])
                        charFrequency[ch-'a']++;
                }
            }
            int scoreOfWord=0;
            for(int i=0; i<26; i++)
            {
                if(charFrequency[i]>charFrequencyOfLetters[i])
                {
                    scoreOfWord=0;
                    break;
                }
                scoreOfWord+=(score[i]*charFrequency[i]);
            }
            if(scoreOfWord > maxScoreOfWords)
            {
                maxScoreOfWords = scoreOfWord;
            }
        
        }
        return maxScoreOfWords;
    }
};
