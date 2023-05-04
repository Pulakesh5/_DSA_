class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<long long> qR, qD;
        int n = senate.size();
        for(int i=0;i<n;i++)
        {
            if(senate[i]=='D')
                qD.push(i);
            else
                qR.push(i);
        }
        long long firstD, firstR;
        while(qD.size() && qR.size())
        {
            firstD = qD.front();
                qD.pop();
            firstR = qR.front();
                qR.pop();
            if(firstD<firstR)
                qD.push(firstD+n);
            else
                qR.push(firstR+n);
        }
        if(qD.size())
            return "Dire";
        return "Radiant";
    }
};
