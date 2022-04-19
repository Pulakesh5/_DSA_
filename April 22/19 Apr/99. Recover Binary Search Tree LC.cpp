class Solution {
public:
    vector<int> vec;
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        process(root);
    }
    
    void process(TreeNode *root){
        if(!root) return;
        process(root->left);
        root->val=vec.back();
        vec.pop_back();
        process(root->right);
    }
    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
};
