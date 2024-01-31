class Solution
{
    public:
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key)
        {
            // code here
            if(!root)
                root = getNode();
            struct TrieNode *head = root; 
            int ch;
            int len = key.size();
            for(int i=0; i<len; i++)
            {
                ch = key[i] - 'a';
                if(head->children[ch]==nullptr)
                {
                    head->children[ch] = getNode();
                }
                head = head->children[ch];
                if(i==len-1)
                    head->isLeaf = true;
            }
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key) 
        {
            // code here
            struct TrieNode *head = root; 
            int ch;
            int len = key.size();
            for(int i=0; i<len; i++)
            {
                ch = key[i] - 'a';
                if(head->children[ch]==nullptr)
                    return false;
                head = head->children[ch];
                if(i==len-1)
                    return head->isLeaf;
            }
        }
};
