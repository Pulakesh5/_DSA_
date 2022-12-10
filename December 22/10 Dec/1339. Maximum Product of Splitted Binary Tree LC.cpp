class Solution {
public:
    long long totalSum=0,ans=0;

    const int mod=1e9+7;

    int maxProduct(TreeNode* root) {
        
        sum(root);

        postorder(root);
        cout<<totalSum<<endl;

        return ans%mod;
    }

    int sum(TreeNode *root)
    {
        if(!root) return 0;
        totalSum+=(root->val);

        sum(root->left);
        sum(root->right);
        
        return totalSum;
    }

    int postorder(TreeNode *root)
    {
        if(!root) return 0;
        long long rval=postorder(root->right);
        long long lval=postorder(root->left);
        
        ans=max({ans,((totalSum-rval)*rval),((totalSum-lval)*lval)});

        return (rval+lval+root->val)%mod;
    }
};
