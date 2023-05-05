class Solution {
public:
    int maxVowels(string s, int k) {
        int vowelCount=0, maxVowelCount=0, n = s.size();
        
        set<int> Vowels = {'a', 'e', 'i', 'o', 'u'};
        
        for(int i=0; i<n; i++)
        {
            if(Vowels.find(s[i])!=Vowels.end())
                vowelCount++;
                
            if(i<k)
            {
                maxVowelCount = max(vowelCount, maxVowelCount);
                continue;
            }
            if(Vowels.find(s[i-k])!=Vowels.end())
                vowelCount--;
            if(vowelCount > maxVowelCount)
                maxVowelCount = vowelCount;
        }
        return maxVowelCount;
    }
};
