class TrieNode{
public:
    TrieNode *next[26];
    bool isword;
    TrieNode(bool flag=false){
        memset(next,0,sizeof(next));
        isword=flag;
    }
};
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *p=root;
        for(int i=0;i<word.length();i++){
            if(p->next[word[i]-'a']==NULL)
                p->next[word[i]-'a'] = new TrieNode();
            p = p->next[word[i]-'a'];
        }
        p->isword=true;
    }
    
    bool search(string word) {
        return bfs(word, 0, root);
    }
private:
    bool bfs(string word, int pos, TrieNode* node){
        
        for(int i=pos;i<word.length() && node; ++i){
            if(word[i]!='.'){
                node = node->next[word[i]-'a'];
            }
            else{
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp ->next[j];
                    if (bfs(word, i + 1, node)) {
                        return true;
                    }
                }
            }
        }
         return node && node ->isword;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
