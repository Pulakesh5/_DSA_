class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int mismatchCount = 0, prevIndex;
        int len = s1.size();
        for(int i=0; i<len; i++)
        {
            if(s1[i]==s2[i])
                continue;
            else if(mismatchCount<2)
            {
                if(mismatchCount==0)
                {
                    prevIndex = i;
                }
                else
                {
                    if(!(s1[prevIndex]==s2[i] && s2[prevIndex]==s1[i]))
                    {
                        // cout<<"First return\n";
                        return false;
                    }
                }
                mismatchCount+=1;
            }
            else
            {
                // cout<<"Second return\n";
                return false;
            }
        }
        return mismatchCount!=1;
    }
};
