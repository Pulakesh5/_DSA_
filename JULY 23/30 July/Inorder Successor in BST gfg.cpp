class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node* successor = NULL;
    bool found = false;
    void inOrder(Node* root, Node* x)
    {
        if(!root)
            return;
        inOrder(root->left, x);
        if(found && !successor)
            successor = root;
        found = (root->data == x->data);
        inOrder(root->right, x);
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        inOrder(root,x);
        return successor;
    }
};
