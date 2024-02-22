class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n), trustedBy(n);
        for(auto rel:trust)
        {
            if(rel[0]==rel[1])
                continue;
            trusts[rel[0]-1]++;
            trustedBy[rel[1]-1]++;
        }
        int judge=-1;
        for(int i=0; i<n; i++)
        {
            if(trusts[i]==0 && trustedBy[i]==n-1)
            {
                if(judge==-1)
                    judge = i+1;
                else
                    return -1;
            }
        }
        return judge;
    }
};
