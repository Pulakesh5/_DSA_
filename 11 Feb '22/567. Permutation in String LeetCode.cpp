class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1=s1.length(),l2=s2.length();
        
        if(l1>l2) return false; //if substring is longer than original then answer is false
        if(s1==s2) return true; // if both are same then answer is true

        vector<int> f1(26,0),f2(26,0);
        
        for(int i=0;i<l1;i++) //filling frequency array of window size l1 with characters of s1
            f1[s1[i]-'a']++;
        
        for(int i=0;i<l1;i++) //filling frequency array of window size l1 with characters of s2
            f2[s2[i]-'a']++;
        
        for(int i=1;i<=(l2-l1);i++){
            if(f1==f2)
                return true;
            f2[s2[i-1]-'a']--; //removing first character of window
            f2[s2[i+l1-1]-'a']++; // adding next character of window to it // sliding the  window
        }
            
        if(f1==f2)
            return true;
        return false;
    }
};
