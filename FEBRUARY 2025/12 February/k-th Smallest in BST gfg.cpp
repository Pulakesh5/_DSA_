class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int kthSmallestNode = -1;
    void traverse(Node* root, int &k)
    {
        if(root == nullptr)
            return;
        
        traverse(root->left, k);
        k--;
        if(k==0)
            kthSmallestNode = root->data;
        traverse(root->right, k);
    }
    int kthSmallest(Node *root, int k) {
        // add code here.
        traverse(root, k);
        return kthSmallestNode;
    }
};
