class TrieNode{
public:
    TrieNode *next[26];
    bool isword;
    TrieNode(bool flag=false){
        memset(next,0,sizeof(next));
        isword=flag;
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *p=root;
        for(int i=0;i<word.length();i++){
            if(p->next[word[i]-'a']==NULL)
                p->next[word[i]-'a'] = new TrieNode();
            p = p->next[word[i]-'a'];
        }
        p->isword=true;
    }
    
    bool search(string word) {
        TrieNode *p = check(word);
        return p!=NULL && p->isword;
    }
    
    bool startsWith(string prefix) {
        TrieNode *p=check(prefix);
        return p!=NULL;
    }
private:
    TrieNode* check(string s){
        TrieNode *p=root;
        for(int i=0;i<s.length() && p!=NULL;i++){
            p=p->next[s[i]-'a'];
        }
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
