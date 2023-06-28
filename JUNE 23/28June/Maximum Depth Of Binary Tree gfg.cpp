class Solution{
  public:
    /*You are required to complete this method*/
    int maxDepth(Node *root) {
        // Your code here
        if(!root)
            return 0;
        return 1+max(maxDepth(root->right),maxDepth(root->left));
    }
};
