class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void traverse(Node* root, vector<int> &trav)
    {
        if(root==nullptr)
            return;
        if(root->left)
            traverse(root->left, trav);
        trav.push_back(root->data);
        if(root->right)
            traverse(root->right, trav);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> traversal;
        traverse(root1, traversal);
        traverse(root2, traversal);
        sort(traversal.begin(), traversal.end());
        return traversal;
    }
};
