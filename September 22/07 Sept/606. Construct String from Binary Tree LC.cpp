class Solution {
public:
    string tree2str(TreeNode* root) {
        return recursion(root);
    }
    
    string recursion(TreeNode* root)
    {
        if(!root) return "";
        string ans=to_string(root->val);
        if(root->left) ans+=("(" + recursion(root->left) +")");
        if(root->right)
        {
            if(!(root->left)) ans+="()";
            ans+=("(" + recursion(root->right) +")");
        }
        return ans;
    }
};
