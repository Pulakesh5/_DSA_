class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> pos(256,-1);
        int start=0,last=-1,n=s.size(),ch;
        int max_length=0;
        
        for(int i=0;i<n;i++){
            ch=s[i];
            if(pos[ch]==-1)
                pos[ch]=i;
            else{
                int next_start=pos[ch]+1;
                
                for(int j=start;j<next_start;j++)
                {
                    ch=s[j];
                    pos[ch]=-1;
                }
                pos[ch]=i;
                max_length=max(max_length,(last-start)+1);
                start=next_start;
            }
            last++;
        }
        max_length=max(max_length,(last-start)+1);
        return max_length;
    }
};
