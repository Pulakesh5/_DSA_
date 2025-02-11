class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    void traverseBST(Node* root, vector<int> &v)
    {
        if(root == nullptr)
            return;
        traverseBST(root->left, v);
        v.push_back(root->data);
        traverseBST(root->right, v);
    }
    bool isBST(Node* root) {
        // Your code here
        vector<int> v, sorted;
        traverseBST(root, v);
        sorted = v;
        sort(v.begin(), v.end());
        return sorted==v;
    }
};
