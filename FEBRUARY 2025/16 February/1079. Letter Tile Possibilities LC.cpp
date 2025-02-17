class Solution {
public:
    int LEN, countPossibleSubsequence;
    vector<int> freq;
    void backtrack(int index)
    {
        countPossibleSubsequence++;
        if(index>=LEN)
        {
            return;
        }
        // backtrack(index+1);
        for(int i=0; i<26; i++)
        {
            if(freq[i]==0)
                continue;
            freq[i]--;
            backtrack(index+1);
            freq[i]++;
        }
    }
    int numTilePossibilities(string tiles) {
        LEN = tiles.size();
        
        freq.resize(26);
        for(char ch:tiles)
            freq[ch-'A']++;
        
        backtrack(0);
        
        return countPossibleSubsequence-1;
    }
};
