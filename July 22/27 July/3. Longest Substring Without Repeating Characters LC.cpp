class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[256];
        memset(pos,-1,sizeof(pos));
        int i=0,count=1,n=s.length();
        int ans=0,p=0;
        for(int j=0;j<n;j++){
            p=(int)s[j];
            if(pos[p]!=-1 && pos[p]>=i){
                i=pos[p];
                i++;
                while(i<j && s[i]==s[j])
                    i++;
            }
            pos[p]=j;
            ans=max(j-i+1,ans);
        }

        return ans;
    }
};
/**********************************************************************************************************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[256];
        memset(pos,-1,sizeof(pos));
       
        int start=-1,n=s.length();
        int ans=0;
        for(int j=0;j<n;j++){
            if(pos[s[j]]>start)
                start=pos[s[j]];
            pos[s[j]]=j;
            ans=max(ans,j-start);
        }
        return ans;
    }
};
