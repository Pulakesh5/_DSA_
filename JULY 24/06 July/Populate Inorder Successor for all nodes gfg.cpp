class Solution {
  public:
    Node* curr = nullptr;
    void populate(Node* root)
    {
        if(root == nullptr)
            return ;
        populate(root->right);
        root->next = curr;
        curr = root;
        populate(root->left);
    }
    void populateNext(Node *root) {
        // code here
        if(root==nullptr)
            return;
        // Node* predec = nullptr;
        populate(root);
    }
};
