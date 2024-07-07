class Solution {
  public:
    // Function should return all the ancestor of the target node
    bool traverse(struct Node* root, int target, vector<int> &anc)
    {
        if(!root)
            return false;
        
        bool flag = traverse(root->left, target, anc);
        flag = flag | traverse(root->right, target, anc);
        if(flag)
            anc.push_back(root->data);
        flag = flag | (root->data==target);
        
        return flag;
    }
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        vector<int> ancestors;
        traverse(root, target, ancestors);
        return ancestors;
    }
};
