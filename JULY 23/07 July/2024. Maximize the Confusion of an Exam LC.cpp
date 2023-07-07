class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        map<char, int> charFreq;
        int i = 0,j;
        int len = answerKey.size(), maxFreq = 0;
        char ch;
        for(j = 0; j<len; j++)
        {
            ch = answerKey[j];
            charFreq[ch]++;
            maxFreq = max(maxFreq, charFreq[ch]);

            if((j-i+1) > maxFreq+k)
            {
                charFreq[answerKey[i++]]--;
            }
        }
        return len - i;
    }
};
