class Solution {
public:
    string pushDominoes(string domino) {
        int lastR=-2,lastL=-1;
        int n=domino.size();
        //string domino(n,'.');
        int j,k;
        for(int i=0;i<n;i++)
        {
            if(domino[i]=='.') continue;
            if(domino[i]=='L')
            {
                if(lastR<lastL)
                {
                    for(j=max(0,lastL);j<i;j++)
                        domino[j]='L';
                    lastL=i;
                }
                else
                {
                    lastL=i;
                    j=lastR+1;
                    k=lastL-1;
                    while(j>=0 && j<k)
                    {
                        if(j>=k) break;
                        domino[j++]='R';
                        domino[k--]='L';
                    }
                }
                
            }
            else
            {
                if(lastL<lastR)
                {
                    for(j=max(0,lastR);j<i;j++)
                        domino[j]='R';
                }
                lastR=i;
            }
        }
        
        if(lastR>lastL)
        {
            for(j=lastR;j<n;j++)
                domino[j]='R';
        }
        
        return domino;
    }
};
