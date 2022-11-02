class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string> _bank{bank.begin(), bank.end()};
        if(!_bank.count(end)) return -1;
        
        queue<string> q;
        q.push(start);
        int step=0,s;
        string str,t;
        
        while(!q.empty())
        {
            s=q.size();
            
            for(int i=0;i<s;i++)
            {
                str=q.front();
                q.pop();
                
                if(str==end) return step;
                _bank.erase(str);
                
                for(int j=0;j<8;j++)
                {
                    t=str;
                    t[j]='A';
                    if(_bank.count(t)) q.push(t);
                    t[j]='C';
                    if(_bank.count(t)) q.push(t);
                    t[j]='G';
                    if(_bank.count(t)) q.push(t);
                    t[j]='T';
                    if(_bank.count(t)) q.push(t);
                }
                
            }
            step++;
        }
        return -1;
        
    }
};
