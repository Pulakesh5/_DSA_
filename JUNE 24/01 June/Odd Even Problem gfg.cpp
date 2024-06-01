class Solution {
  public:
    string oddEven(string s) {
        // code here
        vector<int> freq(26,0);
        int len = s.size();
        for(int pos=0; pos<len; pos++)
        {
            freq[s[pos]-'a']++;
        }
        int count=0;
        for(int i=0; i<26; i++)
        {
            if((i%2)!=(freq[i]%2) && freq[i]>0)
                count++;
        }
        if(count&1)
            return "ODD";
        return "EVEN";
    }
};
