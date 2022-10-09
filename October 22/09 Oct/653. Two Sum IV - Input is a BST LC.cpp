class Solution {
public:
    void inorder(vector<int> &v, TreeNode* root)
    {
        if(!root) return;
        inorder(v,root->left);
        v.push_back(root->val);
        inorder(v,root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(v,root);
        int l=0,r=v.size()-1,sum;
        while(l<r)
        {
            sum=v[l]+v[r];
            if(sum==k) return true;
            if(sum<k) l++;
            else r--;
        }
        return false;
    }
};
