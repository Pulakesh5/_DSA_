class Solution {
public:
    int find(vector<vector<int>> &trustedBy, int judge)
    {
        for(vector<int> vec:trustedBy)
        {
            for(int peep:vec)
                if(peep==judge)
                    return false;
        }
        return true;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<vector<int>> trustedBy(n+1);
        for(vector<int> vec:trust)
        {
            trustedBy[vec[1]].push_back(vec[0]);
        }

        for(int i=1;i<=n;i++)
        {
            if(trustedBy[i].size()==(n-1) && find(trustedBy,i))
                return i;
        }

        return -1;
    }
};
