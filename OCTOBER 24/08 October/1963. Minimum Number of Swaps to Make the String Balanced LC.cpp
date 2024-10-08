#pragma GCC optimize("O3", "unroll-loops")

class Solution {
public:
    int minSwaps(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int N = s.size();
        int lastOpen = N-1;
        while(lastOpen>=0 && s[lastOpen]==']')
            lastOpen--;
        int openningBracket = 0, closingBracket = 0, swapCount = 0;
        for (int i=0; i<N; i++) {
            if(s[i]=='[')
                openningBracket++;
            else
                closingBracket++;
            
            if (openningBracket < closingBracket) {
                // cout<<i<<", "<<lastOpen<<" : "<<swapCount<<endl;
                swap(s[i], s[lastOpen]);
                swapCount++; 
                openningBracket++;
                closingBracket--;
                while(lastOpen>i && s[i]==']')
                    lastOpen--;
            }
        }
        return swapCount;
    }
};
