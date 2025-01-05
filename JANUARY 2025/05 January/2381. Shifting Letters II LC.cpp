class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int N = s.size();
        vector<int> move(N);
        for(auto shift:shifts)
        {
            if(shift[2]==1)
            {
                move[shift[0]]++;
                if(shift[1]+1<N)
                    move[shift[1]+1]--;
            }
            else
            {
                move[shift[0]]--;
                if(shift[1]+1<N)
                    move[shift[1]+1]++;
            }
            
        }
        int shift = 0, pos;
        for(int i=0; i<N; i++)
        {
            shift = (shift+move[i])%26;
            s[i] = (char) ('a'+(s[i]-'a'+shift+26)%26);
        }
        return s;
    }
};
