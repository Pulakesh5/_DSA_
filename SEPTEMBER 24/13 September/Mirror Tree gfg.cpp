class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    Node* flip(Node* node)
    {
        if(node == nullptr)
            return node;
        Node* lTree = flip(node->left);
        Node* rTree = flip(node->right);
        node->left = rTree;
        node->right = lTree;
        return node;
    }
    void mirror(Node* node) {
        // code here
        Node* lTree = flip(node->left);
        Node* rTree = flip(node->right);
        node->left = rTree;
        node->right = lTree;
    }
};
