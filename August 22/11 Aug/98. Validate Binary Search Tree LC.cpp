class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *prev=NULL;
        return validate(root, prev);
    }
    
    bool validate(TreeNode* root, TreeNode* &prev){
        if(!root) return true;
        if(!validate(root->left,prev)) return false;
        if(prev && prev->val >= root->val) return false;
        prev=root;
        return validate(root->right,prev);
    }
};
