class Solution {
public:
    void preorder(TreeNode* root, vector<TreeNode*> &pre){
        if(!root) return;
        pre.push_back(root);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> pre;
        preorder(root,pre);
        TreeNode *head=root;
        int n=pre.size();
        for(int i=1;i<n;i++){
            head->right=pre[i];
            head->left=NULL;
            head=head->right;
        }
    }
};

/***************************************************************************************************************************/

class Solution {
public:
    //Let's do it in post-order
    TreeNode *prev=NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};
