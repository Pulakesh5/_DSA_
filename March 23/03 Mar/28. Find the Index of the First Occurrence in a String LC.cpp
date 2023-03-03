class Solution {
public:
    int strStr(string haystack, string needle) {
        int nh=haystack.size(), nn=needle.size();
        
        for(int i=0;i<nh;i++)
        {
            if(needle[0]==haystack[i])
            {
                bool found=true;
                int k=i+1,j;
                for(j=1;j<nn && k<nh && found;j++,k++)
                    if(needle[j]!=haystack[k]) found=false;
                if(found && j==nn)
                    return i;

            }
        }

        return -1;
    }
};
