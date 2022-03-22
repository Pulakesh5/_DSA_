class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> Idx(26,-1);
        
        int n=s.length();
        //finding last position of char
        for(int i=0;i<n;i++)
            Idx[s[i]-'a']=i;
        
        int MaxIdx=-1,LastIdx=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            MaxIdx=max(MaxIdx,Idx[s[i]-'a']);
            if(i==MaxIdx){
                ans.push_back(MaxIdx-LastIdx+1);
                LastIdx=i+1;
            }
        }
        return ans;
    }
};
