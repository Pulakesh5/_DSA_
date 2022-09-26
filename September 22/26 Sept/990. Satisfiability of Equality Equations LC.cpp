class Solution {
public:
    int uf[26];
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++) uf[i]=i;
        for(auto eq:equations)
        {
            if(eq[1]=='=')
                uf[find(eq[0]-'a')]=find(eq[3]-'a');
        }
        
        for(auto eq:equations)
        {
            if(eq[1]=='!' && find(eq[0]-'a')==find(eq[3]-'a'))
                return false;
        }
        
        return true;
    }
    int find(int x)
    {
        if(x!=uf[x]) uf[x]=find(uf[x]);
        
        return uf[x];
    }
};
