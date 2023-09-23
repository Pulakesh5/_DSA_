class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<int,vector<string>> lenMap;
        map<string, int> len;
        
        for(string word:words)
        {
            lenMap[-1*word.size()].push_back(word);
            len[word] = 1;
        }
        
        string prev;
        int maxChain = 1;
        for(auto it:lenMap)
        {
            
            for(string word:it.second)
            {
                prev = word.substr(1);
                if(len.find(prev)!=len.end())
                {
                    len[prev] = len[word] + 1;
                    maxChain = max(maxChain, len[word]+1);
                }
                
                for(int i=1; i<word.size()-1; i++)
                {
                    prev = "";
                    prev+=word.substr(0,i);
                    prev+=word.substr(i+1);
                    
                    if(len.find(prev)!=len.end())
                    {
                        len[prev] = len[word] + 1;
                        maxChain = max(maxChain, len[word]+1);
                    }
                }
                prev = word.substr(0,word.size()-1);
                if(len.find(prev)!=len.end())
                {
                    len[prev] = len[word] + 1;
                    maxChain = max(maxChain, len[word]+1);
                }

            }
        }
        
        return maxChain;
    }
};
