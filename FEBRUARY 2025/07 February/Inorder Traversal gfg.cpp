class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> v;
    void traverse(Node* root)
    {
        if(!root)
            return;
        traverse(root->left);
        v.push_back(root->data);
        traverse(root->right);
    }
    vector<int> inOrder(Node* root) {
        // Your code here
        traverse(root);
        return v;
    }
};
