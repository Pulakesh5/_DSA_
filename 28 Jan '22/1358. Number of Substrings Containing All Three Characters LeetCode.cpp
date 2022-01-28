// This is also a fantastic use of sliding window, please try this question again before jumping into the solution 
class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3]={0,0,0}, i=0, n=s.length();
        int ans=0;
        for(int j=0; j < n;j++){
            count[s[j]-'a']++;
            
            while(count[0] && count[1] && count[2])
                --count[s[i++]-'a'];
            //cout<<i<<" "<<j<<'\n';
            ans+=i;
        }
        //cout<<'\n';
        return ans;
    }
};
