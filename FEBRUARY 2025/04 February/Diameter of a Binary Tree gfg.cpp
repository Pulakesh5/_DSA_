class Solution {
  public:
    int DIAMETER = 0;
    int height(Node* root)
    {
        if(!root)
            return 0;
        int lheight = height(root->left);
        int rheight = height(root->right);
        DIAMETER = max(DIAMETER, lheight+rheight);
        return 1+max(lheight, rheight);
    }
    int diameter(Node* root) {
        // Your code here
        height(root);
        return DIAMETER;
    }
};
