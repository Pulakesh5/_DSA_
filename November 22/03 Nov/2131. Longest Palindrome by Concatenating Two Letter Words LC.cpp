class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> same,notSame;
        for(string word:words)
        {
            if(word[0]==word[1]) same[word]++;
            else    notSame[word]++;
        }
        int sameOddCountMax=0;
        string sameString="";
        
        for(auto it:same){
            if((it.second)&1 && it.second>sameOddCountMax)
            {
                sameString=it.first;
                sameOddCountMax=max(it.second,sameOddCountMax);
            }
            
        }
        
        int wordCount=0;
        for(auto it:notSame)
        {
            string t=it.first;
            reverse(t.begin(), t.end());
            
            if(notSame.find(t)!=notSame.end())
                wordCount+=min(notSame[t],it.second);
            //cout<<it.first<<": "<<wordCount<<endl;
        }
        
        for(auto it:same)
        {
            if(it.first!=sameString)
                wordCount+=(2*(it.second/2));
        }
        wordCount+=sameOddCountMax;
        
//         cout<<endl;
//         for(auto it:same) cout<<it.first<<": "<<it.second<<endl;
//         cout<<endl;
//         for(auto it:notSame) cout<<it.first<<": "<<it.second<<endl;
        
        return (2*wordCount);
        
    }
};
