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
    int level[100005] = {}, depth[100005] = {};
    int d1[100005] = {}, d2[100005] = {}; // d1->largest depth at a level, d2->second largest depth at a level
    int traverse(TreeNode* root, int l) {
        if(root == nullptr)
            return 0;
        level[root->val] = l;
        depth[root->val] = 1+max(traverse(root->left, l+1), traverse(root->right, l+1));
        if(d1[l]<depth[root->val])
        {
            d2[l] = d1[l];
            d1[l] = depth[root->val];
        }
        else if(d2[l] < depth[root->val])
            d2[l] = depth[root->val];
        return depth[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverse(root, 0);
        int l;
        for(int &q:queries)
        {
            l = level[q];
            q = l + (d1[l] == depth[q] ? d2[l] : d1[l]) - 1;
        }
        return queries;
    }
};
