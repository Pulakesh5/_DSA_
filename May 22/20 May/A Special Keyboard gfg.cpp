class Solution {
  public:
    int findTime(string S1, string S2) {
        int last=0,curr=0;
        int time_=0;
        int position[26]={0};
        int n=S2.length();
        
        for(int i=0;i<26;i++)
            position[S1[i]-'a']=i;
        
        for(int i=0;i<n;i++){
            curr=position[S2[i]-'a'];
            time_+=abs(curr-last);
            last=curr;
        }
        
        return time_;
    }
};
