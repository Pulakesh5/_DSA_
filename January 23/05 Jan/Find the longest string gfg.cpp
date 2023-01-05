class Solution
{
public:
    static bool cmp(string &a, string &b)
    {
        if(a.size()!=b.size()) return a.size()<b.size();
        return a>b;
    }
    string longestString(vector<string> &words)
    {
        // code here
        map<string,int> mp;
        for(string word:words)
        {
            mp[word]++;
        }
        sort(words.begin(), words.end(), cmp);
        int wordCount=words.size();
        for(int i=wordCount-1;i>=0;i--)
        {
            bool exists=true;
            string pre="";
            int len=words[i].size();
            for(int j=0;j<len;j++)
            {
                pre.push_back(words[i][j]);
                if(mp[pre]==0)
                {
                    exists=false;
                    break;
                }
            }
            if(exists) return words[i]; 
        }
        
        return "";
    }
};
