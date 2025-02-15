class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        if(!root)
            return root;
        
        if(root->data == n1->data || root->data == n2->data)
            return root;
        
        Node* ltree = LCA(root->left, n1, n2);
        Node* rtree = LCA(root->right, n1, n2);
        
        if(!ltree)
            return rtree;
        if(!rtree)
            return ltree;
        return root;
    }
};
