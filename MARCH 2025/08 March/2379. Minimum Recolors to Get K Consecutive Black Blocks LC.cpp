class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // count[i] => count of black blocks upto i-th blocks
        int N = blocks.size();
        vector<int> count(N+1,0); 
        int minOps = 0;
        for(int i=1; i<=N; i++)
        {
            count[i] = count[i-1];
            count[i] += (blocks[i-1]=='B');
            if(i>=k)
                minOps = max(minOps, count[i]-count[i-k]);
        }
        return k-minOps;
    }
};
