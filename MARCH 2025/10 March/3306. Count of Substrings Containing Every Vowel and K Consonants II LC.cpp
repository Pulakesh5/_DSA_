class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        map<char,int> count;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int LEN = word.size();
        int consonant = 0;
        long long substring = 0;
        vector<int> nextConsonant(LEN);
        int last = LEN;
        for(int i=LEN-1; i>=0; i--)
        {
            nextConsonant[i] = last;
            if(vowels.find(word[i])==vowels.end())
                last = i;
        }
        for(int left=0, right=0; right<LEN; right++)
        {
            if(vowels.find(word[right]) != vowels.end())
                count[word[right]]++;
            else
            {
                consonant++;
                while(consonant>k)
                {
                    if(vowels.find(word[left]) != vowels.end())
                    {
                        count[word[left]]--;
                        if(count[word[left]]==0)
                            count.erase(word[left]);
                    }
                    else
                    {
                        consonant--;
                    }
                    left++;
                }
            }
            
            while(left<right && count.size() == 5 and consonant==k) {
                substring += (0ll + (nextConsonant[right]-right));
                if(vowels.find(word[left]) != vowels.end())
                {
                    count[word[left]]--;
                    if(count[word[left]]==0)
                        count.erase(word[left]);
                }
                else
                    consonant--;
                left++;
            }
        }
        return substring;
    }
};
