class Solution {
public:
    int findTheLongestSubstring(string s) {
        int totalVowel = 0;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        map<char, int> pos;
        pos['a'] = 0;
        pos['e'] = 1;
        pos['i'] = 2;
        pos['o'] = 3;
        pos['u'] = 4;

        int N = s.size();
        int bitmask = 0, longestSubString = 0;
        map<int, int> hash;
        hash[0] = -1;
        for(int i=0; i<N; i++)
        {
            if(vowels.find(s[i])!=vowels.end())
            {
                bitmask ^= (1<<pos[s[i]]);
                if(hash.find(bitmask)==hash.end())
                    hash[bitmask] = i;
            }
            longestSubString = max(longestSubString, i-hash[bitmask]);
        }
        return longestSubString;
    }
};
