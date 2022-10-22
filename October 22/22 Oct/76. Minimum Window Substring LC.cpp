class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> t_count(60,0),window(60,0);
        
        for(char ch:t) t_count[ch-'A']++;
        
        int n=s.size(), matched=0, left=0;
        int windowSize=INT_MAX;
        char ch;
        string subString;
        for(int i=0;i<n;i++)
        {
            ch=s[i]-'A';
            window[ch]++;
            if(window[ch]<=t_count[ch])
                matched++;
            if(matched<t.size()) continue;
            ch=s[left]-'A';
            while(left<=i && window[ch]>t_count[ch])
            {
                left++;
                if(left>i)
                {
                    left--;
                    break;
                }
                window[ch]--;
                ch=s[left]-'A';
            }
            if((i-left+1)<windowSize)
            {
                windowSize=i-left+1;
                subString="";
                for(int j=left;j<=i;j++)
                    subString+=s[j];
            }
            
        }
        return subString;
    }
};
