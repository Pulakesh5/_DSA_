class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9+7;
        vector<long> state = {1, 1, 0, 1, 0, 0, 0}, prevState(7);
        // state[0] : end with A
        // state[1] : end with P and 0 A before
        // state[2] : end with P and 1 A before
        // state[3] : end with 1 L and 0 A before
        // state[4] : end with 1 L and 1 A before
        // state[5] : end with 2 L and 0 A before
        // state[6] : end with 2 L and 1 A before
        for(int i=2; i<=n; i++)
        {
            prevState[0] = ((state[1] + state[3])%MOD + state[5])%MOD; // PA + LA + LLA
            prevState[1] = prevState[0]; // P, 0A
            prevState[2] = (((state[0] + state[2])%MOD + state[4])%MOD + state[6])%MOD; // AP + PP, A
            prevState[3] = state[1]; // PL, 0A
            prevState[4] = (state[0] + state[2])%MOD; // AL + PL,1A
            prevState[5] = state[3];// LL, 0A
            prevState[6] = state[4]; // LL,1A
            state = prevState;
        }
        long long ans=0;
        for(auto v:state)
        {
            cout<<v<<" "<<endl;
            ans = (ans+v)%MOD;
        }
        return ans;
    }
};
