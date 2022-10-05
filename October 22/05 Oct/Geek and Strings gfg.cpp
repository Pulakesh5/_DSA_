    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        // code here
        string pre="";
        int n;
        unordered_map<string,int> mp;
        for(int i=0;i<N;i++)
        {
            pre="";
            n=li[i].size();
            for(int j=0;j<min(n,100);j++)
            {
                pre+=li[i][j];
                mp[pre]++;
            }
        }
        vector<int> count(Q,0);
        
        for(int i=0;i<Q;i++)
            count[i]=mp[query[i]];
        
        return count;
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TrieNode{
    public:
        int count;
        TrieNode* nxt[26];
        TrieNode(){
            count=0;
            for(int i=0;i<26;i++)
                nxt[i]=NULL;
        }
};

class Solution{
public:
    void insert(TrieNode* root, string str)
    {
        int n=str.size(),index;
        TrieNode* head=root;
        for(int i=0;i<min(n,100);i++)
        {
            index=str[i]-'a';
            if(!(head->nxt[index]))  head->nxt[index] = new TrieNode();
            (head->nxt[index]->count)++;
            head=head->nxt[index];
        }
    }
    
    int countOfWord(TrieNode* root, string pre)
    {
        int index;
        TrieNode* head=root;
        for(int i=0;i<pre.size();i++)
        {
            index=pre[i]-'a';
            if(!(head->nxt[index])) return 0;
            head=head->nxt[index];
        }
        return head->count;
    }
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        // code here
        TrieNode *root= new TrieNode();
        for(int i=0;i<N;i++)
        {
            insert(root,li[i]);
        }
        vector<int> count(Q,0);
        
        for(int i=0;i<Q;i++)
            count[i]=countOfWord(root,query[i]);
        
        return count;
    }
};
