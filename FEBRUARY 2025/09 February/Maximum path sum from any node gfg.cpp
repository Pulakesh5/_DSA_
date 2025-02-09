class Solution {
  public:
    // Function to return maximum path sum from any node in a tree.
    int traverse(Node *root, int &maxSumPath)
    {
        if(root == nullptr)
            return 0;
        
        int lTree = traverse(root->left, maxSumPath);
        int rTree = traverse(root->right, maxSumPath);
        
        maxSumPath = max(maxSumPath, root->data + max(0, lTree)+ max(0, rTree));
        
        // cout<<root->data<<" : "<<lTree<<"  "<<rTree<<" -> maxPath = "<<maxSumPath<<endl;
        
        return root->data + max({0, lTree, rTree});
    }
    int findMaxSum(Node *root) {
        // code here
        int maxSumPath = INT_MIN;
        traverse(root, maxSumPath);
        return maxSumPath;
    }
};
