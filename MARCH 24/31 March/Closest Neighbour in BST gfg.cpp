class Solution {
  public:
    int findMaxForN(Node* root, int n) {
        // code here
        if(root==nullptr)
            return -1;
        
        else if(root->key==n)
            return n;
        else if(root->key<n)
            return max(root->key, findMaxForN(root->right, n));
        else if(root->key>n)
            return findMaxForN(root->left, n);
    }
};
