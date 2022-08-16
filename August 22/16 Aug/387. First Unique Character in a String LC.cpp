class Solution {
public:
    
    int firstUniqChar(string s) {
        vector<int> occurence(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++){
            if(occurence[s[i]-'a']==-1)
                occurence[s[i]-'a']=i;
            else
                occurence[s[i]-'a']=-2;
        }
        int pos=INT_MAX;
        for(int i=0;i<26;i++){
            if(occurence[i]>=0)
                pos=min(pos,occurence[i]);
        }
        
        return (pos==INT_MAX?-1:pos);
    }
};
