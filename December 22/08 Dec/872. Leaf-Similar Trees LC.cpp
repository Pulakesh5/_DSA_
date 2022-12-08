class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        process(root1,v1);
        process(root2,v2);

        return v1==v2;
    }

    void process(TreeNode *root, vector<int> &v)
    {
        if(!root) return;
        if(!(root->left) && !(root->right)) v.push_back(root->val);

        process(root->left,v);
        process(root->right,v);
    }
};
