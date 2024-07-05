class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int lWidth=0, rWidth=0;
    void traverse(Node* root, int width) {
        if(root==nullptr)
            return;
        lWidth = min(lWidth, width);
        rWidth = max(rWidth, width);
        traverse(root->left, width-1);
        traverse(root->right, width+1);
    }
    int verticalWidth(Node* root) {
        // code here
        if(root==nullptr)
            return 0;
        traverse(root, 0);
        return (rWidth-lWidth+1);
    }
};
