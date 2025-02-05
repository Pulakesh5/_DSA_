class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    Node* flip(Node* node)
    {
        if(!node)
            return node;
        Node* ltree = flip(node->left);
        Node* rtree = flip(node->right);
        node->left = rtree;
        node->right = ltree;
        return node;
    }
    void mirror(Node* node) {
        // code here
        Node* ltree = flip(node->left);
        Node* rtree = flip(node->right);
        node->left = rtree;
        node->right = ltree;
        // return node;
    }
};
