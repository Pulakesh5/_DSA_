class Solution
{
    public:
    void traverse(Node* root, Node* &pre, Node* &suf, int preVal, int sufVal, int key)
    {
        if(!root) return;
        int val = root->key;
        if(val>key && val<sufVal)
        {
            sufVal = val;
            suf = root;
        }
        if(val<key && val>preVal)
        {
            preVal = val;
            pre = root;
        }
        traverse(root->left, pre, suf, preVal, sufVal, key);
        traverse(root->right, pre, suf, preVal, sufVal, key);
        
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suf, int key)
    {
        // Your code goes here
        int sufVal=INT_MAX, preVal=INT_MIN;
        traverse(root, pre, suf, preVal, sufVal, key);
    }
};
