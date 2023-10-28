class Solution {
public:
    int MOD = 1e9+7;
    int countVowelPermutation(int n) {
        map<char, vector<char>> follows;
        map<int,map<char,int>> counts;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        follows['a'] = {'e'};
        follows['e'] = {'a', 'i'};
        follows['i'] = {'a', 'e', 'o', 'u'};
        follows['o'] = {'i', 'u'};
        follows['u'] = {'a'};

        counts[1]['a'] = 1;
        counts[1]['e'] = 1;
        counts[1]['i'] = 1;
        counts[1]['o'] = 1;
        counts[1]['u'] = 1;

        for(int i=2; i<=n; i++)
        {
            for(char vowel:vowels)
            {
                for(char follow:follows[vowel])
                    counts[i][follow] = (counts[i][follow] + counts[i-1][vowel])%MOD;
            }
        }

        long long countPermutation = 0;
        
        for(char vowel:vowels)
            countPermutation = (countPermutation + counts[n][vowel])%MOD;
        
        return countPermutation;
    }
};
