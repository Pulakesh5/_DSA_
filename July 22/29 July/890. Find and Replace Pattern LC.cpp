class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern){
        
        string _pattern=replace(pattern);
        vector<string> match;
        for(auto word:words){
            if(replace(word)==_pattern)
                match.push_back(word);
        }
        return match;
    }
    string replace(string str){
        
        map<char,char> mp;
        string replacement="";
        int n=str.size(),c=0;
        
        for(int i=0;i<n;i++){
            if(mp.find(str[i])==mp.end())
                mp[str[i]]=('0'+c++);
            replacement+=mp[str[i]];
        }
        mp.clear();
        return replacement;
    }
};
