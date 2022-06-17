class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),start=0,end=-1,maxLength=0;
        vector<int> lp(256,-1);
        
        for(int i=0;i<n;i++){
             if(lp[s[i]] != -1){
                int next_start=lp[s[i]]+1;
                for(int j=start;j<next_start;j++)
                    lp[s[j]]=-1;
                maxLength=max(maxLength,end-start+1);
                start=next_start;
            }
            lp[s[i]]=i;
            end++;
        }
        maxLength=max(maxLength,end-start+1);
        
        return maxLength;
        
    }
};
