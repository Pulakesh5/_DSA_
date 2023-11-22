class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool check(struct Node* left, struct Node* right)
    {
        if(!left && !right)
            return true;
        if(!left || !right || left->data != right->data)
            return false;
        return check(left->right, right->left) && check(left->left, right->right);
    }
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(!root)
	        return true;
	    return check(root->left, root->right);
    }
};
