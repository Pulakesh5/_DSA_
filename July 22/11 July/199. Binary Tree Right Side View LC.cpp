class Solution {
public:
    vector<int> ans;
    int maxHeight = -1;
    vector<int> rightSideView(TreeNode* root) {
        rec(root,0);
        return ans;
    }
    void rec(TreeNode* root, int height){
        if(!root) return;
        if(height>maxHeight){
            ans.push_back(root->val);
            maxHeight=height;
        }
        rec(root->right,height+1);
        rec(root->left,height+1);
    }
};
