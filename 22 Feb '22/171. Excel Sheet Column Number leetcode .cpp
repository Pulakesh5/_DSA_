class Solution {
public:
    int titleToNumber(string str) {
        int n=str.length();
        int ans=0;
        for(int i=0;i<n;i++){
            ans*=26;
            ans+=(str[i]-'A'+1);
        }
        
        return ans;
    }
};
