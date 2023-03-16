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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int li = 0, ri = postorder.size() - 1;
        int lp =li, rp = ri;

        return makeTree(inorder, postorder, li, ri, lp, rp);
    }

    TreeNode* makeTree(vector<int> &inorder, vector<int> &postorder, int li, int ri, int lp, int rp)
    {
        if(li>ri || lp>rp) return NULL;
        int k;
        for(int i=li;i<=ri;i++)
        {
            if(postorder[rp]==inorder[i])
            {
                k=i;
                break;
            }
        }
        TreeNode* root = new TreeNode(inorder[k]);
        int ltree = (k-1-li+1);
        int rtree = (ri-k);
        root->left = makeTree(inorder, postorder, li, k-1, lp, lp + ltree -1);
        root->right = makeTree(inorder, postorder, k+1, ri, lp + ltree, rp - 1);

        return root;
    }
};
