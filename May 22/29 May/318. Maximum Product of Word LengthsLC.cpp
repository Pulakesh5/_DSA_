class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> count(n,vector<int>(26,0));
        int len;
        for(int i=0;i<n;i++){
            len=words[i].length();
            for(int j=0;j<len;j++)
                count[i][words[i][j]-'a']++;
        }
        bool share=false;
        int ans=0,len1,len2;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                share=false;
                len1=words[i].length();
                len2=words[j].length();
                for(int c=0;c<26;c++){
                    if(count[i][c]>0 && count[j][c]>0)
                    {
                        share=true;
                        break;
                    }
                }
                if(!share) ans=max(ans,len1 * len2);
            }
        }
        return ans;
    }
};
