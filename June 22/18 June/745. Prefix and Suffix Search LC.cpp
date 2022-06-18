class WordFilter {
    private:
        unordered_map<string,int> mp;
    public:
    WordFilter(vector<string>& words) {
        int count=words.size();
        string pre,suf,word;
        for(int i=0;i<count;i++){
            word=words[i];
            int length=word.length();
            pre="";
            for(int j=0;j<length;j++){
                pre+=word[j];
                suf="";
                for(int k=length-1;k>=0;k--){
                    suf=word[k]+suf;
                    mp[pre+'|'+suf]=i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return mp[prefix+'|'+suffix]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
