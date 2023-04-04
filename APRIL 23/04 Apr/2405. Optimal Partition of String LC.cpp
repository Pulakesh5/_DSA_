class Solution {
public:
    int partitionString(string s) {
        int len=s.size();
        vector<int> freq(26,0);
        int partition=0;
        for(int i=0;i<len;i++)
        {
            if(freq[s[i]-'a']>0)
            {
                partition++;
                fill(freq.begin(), freq.end(),0);
                freq[s[i]-'a']=1;
            }
            else
                freq[s[i]-'a']=1;
        }
        partition++;
        return partition;
    }
};
