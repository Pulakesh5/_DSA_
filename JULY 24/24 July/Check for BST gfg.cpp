class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool traverse(Node* root, vector<int> &v)
    {
        if(root==nullptr)
            return true;
        bool left = traverse(root->left, v);
        
        if(v.empty() || (v.back()<root->data))
            v.push_back(root->data);
        else
            return false;
        
        bool right = traverse(root->right, v);
        return left && right;
    }
    bool isBST(Node* root) {
        // Your code here
        vector<int> v;
        return traverse(root, v);
    }
};
