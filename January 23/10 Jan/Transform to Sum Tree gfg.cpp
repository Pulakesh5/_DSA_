    void toSumTree(Node *node)
    {
        SumTree(node);
    }
    int SumTree( Node* root)
    {
        if(!root) return 0;
        int lval = SumTree(root->left);
        int rval = SumTree(root->right);
        int sum = lval+rval+root->data;
        root->data=lval+rval;
        return sum;
    }
