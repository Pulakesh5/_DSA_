
//  This is wonderful question and great use of Trie data structure 
//  Try to solve it again without seeing solution

class TrieNode{
public:
    TrieNode *child[2]; //size 2 because each bit position(node) have 0 or 1 bit
    TrieNode(){
        this->child[0]=NULL;
        this->child[1]=NULL;
    }
};
class Solution {
    TrieNode *root;
    
    void TrieInsert(int num){
        bitset<32> bs(num);
        TrieNode *t=root;
        for(int i=31;i>=0;i--){
            if(!t->child[bs[i]])
                t->child[bs[i]]=new TrieNode();
            t=t->child[bs[i]];
        }
    }
    int MaxXOR(int n){
        TrieNode *t=root;
        bitset<32> bs(n);
        int ans=0;
        for(int i=31;i>=0;i--){
            if(t->child[!bs[i]])
            {
                ans+=(1<<i);
                t=t->child[!bs[i]];
            }
            else
                t=t->child[bs[i]];
        }
        return  ans;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for(auto &n:nums)
            TrieInsert(n);
        int ans=0;
        for(auto &n:nums){
            ans=max(ans, MaxXOR(n));
        }
        return ans;
    }

};
