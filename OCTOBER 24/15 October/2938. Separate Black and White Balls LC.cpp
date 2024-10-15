class Solution {
public:
    long long minimumSteps(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        long long minimumStep = 0, pos = 0;
        int N = s.size();
        for(int i=0; i<N; i++) {
            if(s[i]=='0') {
                minimumStep += (i-pos);
                pos++;
            }
        }
        return minimumStep;
    }
};
