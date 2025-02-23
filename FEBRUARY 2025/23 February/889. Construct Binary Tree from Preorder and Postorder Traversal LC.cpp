/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> post, pre;
    TreeNode* constructNode(int pre_l, int pre_r, int post_l, int post_r)
    {
        if(pre_l>pre_r || post_l>post_r)
            return nullptr;
        if(pre_l == pre_r || post_l == post_r)
            return new TreeNode(pre[pre_l]);
        
        int left_start = pre[pre_l+1], i;
        for(i=post_l; i<=post_r; i++)
        {
            if(post[i] == left_start)
                break;
        }
        int lTreeSize = (i-post_l)+1;
        int rTreeSize = (post_r-i)-1;
        
        TreeNode* node = new TreeNode(pre[pre_l]);
        node->left = constructNode(pre_l+1, pre_l+lTreeSize, post_l, i);
        node->right = constructNode(pre_l+lTreeSize+1, pre_r, i+1, post_r-1);

        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        pre = preorder;
        post = postorder;
        return constructNode(0, n-1, 0, n-1);
    }
};
