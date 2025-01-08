class Solution {
public:
    bool isPrefixAndSuffix(string &a, string &b)
    {
        int lena = a.size(), lenb = b.size();
        for(int i=0, j=lenb-lena; i<lena; i++, j++)
        {
            if(a[i]!=b[i] || a[i]!=b[j])
                return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        for(int i=0; i<(n-1); i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(words[i].size()<=words[j].size() && isPrefixAndSuffix(words[i], words[j]))
                    count++;
            }
        }
        return count;
    }
};
