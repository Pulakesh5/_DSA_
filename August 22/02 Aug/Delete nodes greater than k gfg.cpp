class Solution{
  public:
    /*The function should return the root of the modified tree*/
    Node* deleteNode(Node* root, int k)
    {
        if(!root) return root;
        if(root->data < k){
            root->right = deleteNode(root->right,k);
            return root;
        }
        else{
            root->left = deleteNode(root->left,k);
            return root->left;
        }
    }
};
