class TrieNode {
public:
    bool isWord;
    int index;
    TrieNode* next[26];

    TrieNode(bool flag = false) {
        isWord = flag;
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    public:
    void AddWord(string word, int pos) {
        TrieNode* rootNode = root;
        for(char ch:word)
        {
            if(rootNode->next[ch-'a'] == nullptr)
                rootNode->next[ch-'a'] = new TrieNode();
            rootNode = rootNode->next[ch-'a'];
        }
        rootNode->isWord = true;
        rootNode->index = pos; 
    }
    int FindWord(string word) {
        TrieNode* rootNode = root;

        for(int i=0; i<word.size() && rootNode!=nullptr; i++)
        {
            if(rootNode!= nullptr && rootNode->isWord)
                return rootNode->index;
            rootNode = rootNode->next[word[i]-'a'];
        }
        
        if(rootNode!=nullptr && rootNode->isWord)
            return rootNode->index;
        return -1;
    }
};

class Solution {
public:
   string replaceWords(vector<string> &dictionary, string sentence) {
        Trie* trie = new Trie();
        int i=0;
        for(string word:dictionary)
        {
            trie->AddWord(word, i++);
        }
        string rootString="";
        stringstream ss(sentence);
        string word;
        while(ss>>word)
        {
            int index = trie->FindWord(word);
            if(index==-1)
                rootString+=word;
            else
                rootString+=dictionary[index];
            rootString.push_back(' ');
        }
        rootString.pop_back();
        return rootString;
    }
};
