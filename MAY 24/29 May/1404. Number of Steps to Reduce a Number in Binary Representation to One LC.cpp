class Solution {
public:
    int numSteps(string s) {
        int step=0;
        int len = s.size();
        for(int i=len-1; i>0; )
        {
            int j=i;
            while(j>=0 && s[j]=='1')
                j--;
            step+=(i-j+1);
            if(i==j)
            {
                i=i-1;
            }
            else
            {
                i=j;
                if(j>=0)
                    s[j] = '1';
            }
        } 
        return step;
    }
};
