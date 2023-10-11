class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int flag = 1e9+7;
    int height(Node* root)
    {
        if(!root)
            return 0;
        return  1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(!root)
            return true;
        if(!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        if(abs(height(root->left) - height(root->right)) <= 1)
            return true;
        return false;
        
    }
};
