class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int max_d=-1;
    int height(Node *root){
        if(!root) return 0;
        int h1=height(root->left);
        int h2=height(root->right);
        if(h1+h2+1>max_d) max_d=(h1+h2+1);
        return max(h1, h2)+1;
    }
    int diameter(Node* root) {
        height(root);
        return max_d;
    }
};
