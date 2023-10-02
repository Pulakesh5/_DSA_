class Solution {
public:
    bool winnerOfGame(string colors) {
        int A, B;
        int alice = 0, bob = 0;
        int i = 0, len = colors.size();
        
        while(i<len)
        {
            A = 0;
            B = 0;
            if(colors[i]=='A')
            {
                while( i<len && colors[i]=='A')
                    i++, A++;
                alice+= max(0, A-2);
            }
            else if(colors[i]=='B')
            {
                while(i<len && colors[i] == 'B')
                    i++, B++;
                bob+= max(0, B-2);
            }
        }
        return alice>bob;
    }
};
