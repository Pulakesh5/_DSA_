class Solution {
public:
    bool canBeValid(string s, string locked) {
        int len = s.size();
        if(len&1)
            return false;
            
        stack<int> openbracket, unlockedbracket;
        for(int i=0; i<len; i++)
        {
            if(locked[i]=='1')
            {
                if(s[i]==')')
                {
                    if(!openbracket.empty())
                        openbracket.pop();
                    else if(!unlockedbracket.empty()>0)
                        unlockedbracket.pop();
                    else
                    {
                        // cout<<i<<" : open = "<<open<<" unlocked = "<<unlocked<<endl;
                        return false;
                    }
                }
                else
                {
                    openbracket.push(i);
                }
            }
            else
                unlockedbracket.push(i);
        }
        while(!openbracket.empty() && !unlockedbracket.empty() && openbracket.top()<unlockedbracket.top())
        {
            openbracket.pop();
            unlockedbracket.pop();
        }
        return (openbracket.empty());
    }
};
