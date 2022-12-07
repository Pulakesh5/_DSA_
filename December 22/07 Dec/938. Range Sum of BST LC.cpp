class Solution {
public:
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        lbound=low;
        ubound=high;
        dfs(root);
        return sum;
    }
private:
    int sum=0,lbound,ubound;
    void dfs(TreeNode *root)
    {
        if(!root) return;
        dfs(root->left);
        if(root->val>=lbound && root->val<=ubound) sum+=(root->val);
        dfs(root->right);
    }
};
