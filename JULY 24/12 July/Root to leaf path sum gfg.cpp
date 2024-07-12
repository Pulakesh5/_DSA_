class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        // Your code here
        if(root==nullptr)
            return false;
        if(root->left==nullptr && root->right==nullptr)
            return root->data==target;
        target = target - root->data;
        return hasPathSum(root->left, target) or hasPathSum(root->right, target);
    }
};
