//Simple O(n) solution using sliding window of constant size 3;
class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0,j=2,n=s.length(),count=0;
        
        while(i<j && j<n){
            if(s[i]!=s[j] && s[j-1]!=s[j] && s[i]!=s[i+1])
            {
                count++;
            }
            i++;j++;
        }
        return count;
    }
};
// Generic sliding window technic to check if unique char's present in window or not;
class Solution {
public:
    int countGoodSubstrings(string str) {
        int count[123]={},repeat=0, res=0, n=str.length();
        int window=3;
        for(int i=0;i<n;++i){
            repeat += ( count[str[i]]++ == 1);
            repeat -= (i>=window && count[str[i-window]]-- ==2);
            res += (i >= window-1 && repeat==0);
        }
        return res;
    }
};
