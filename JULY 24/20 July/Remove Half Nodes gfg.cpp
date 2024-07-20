// Return the root of the modified tree after removing all the half nodes.
class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        // code here
        if(root==nullptr)
            return nullptr;
        Node *lTree = RemoveHalfNodes(root->left);
        Node *rTree = RemoveHalfNodes(root->right);
        if(root->right==nullptr && root->left!=nullptr)
            root = lTree;
        else if(root->right!=nullptr && root->left==nullptr)
            root = rTree;
        else if(root->right!=nullptr && root->left!=nullptr)
        {
            root->left = lTree;
            root->right = rTree;
        }
        return root;
    }
};
