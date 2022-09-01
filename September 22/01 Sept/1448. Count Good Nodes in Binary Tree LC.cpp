class Solution {
public:
    int countGoodNodes=0;
    int goodNodes(TreeNode* root) {
        int maxNode=INT_MIN;
        count(maxNode,root);
        return countGoodNodes;
    }
    
    void count(int maxNode, TreeNode *root)
    {
        if(!root) return;
        if(maxNode<=(root->val)) countGoodNodes++;
        
        maxNode = max(maxNode,(root->val));
        
        count(maxNode,root->right);
        count(maxNode,root->left);
        
    }
};
