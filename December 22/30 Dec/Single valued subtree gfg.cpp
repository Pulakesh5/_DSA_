class Solution
{
    public:
    int subTreeCount=0;
    int singlevalued(Node *root)
    {
        //code here
        process(root);
        return subTreeCount;
    }
    bool process(Node* root)
    {
        if(!root) return true;
        
        bool lval=process(root->left);
        bool rval=process(root->right);
        
        if(lval && rval)
        {
            if(root->left && (root->data)!=(root->left->data)) return false;
            
            if(root->right && (root->data)!=(root->right->data)) return false;
            
            subTreeCount++;
            return true;
        }
        return false;
    }
};
