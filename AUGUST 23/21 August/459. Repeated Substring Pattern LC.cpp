class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size(), l;
        // string subStr = "";
        bool mismatched = false;
        for(int i=0; i<len; i++)
        {
            // subStr.push_back(s[i]);
            l = i+1;
            if(len%l != 0)
                continue;
            cout<<"checking substr of len "<<l<<endl;
            mismatched = false;
            for(int k=1; k<(len/l) && !mismatched; k++)
            {
                for(int j=k*l; j<((k+1)*l); j++)
                {
                    if(s[j]!=s[j-l])
                    {
                        cout<<"mismatched @ "<<j<<" , "<<j-l<<endl;
                        mismatched = true;
                        break;
                    }
                    
                }
            }
            if(!mismatched && i!=(len-1))
                return true;
        }
        return false;
    }
};
