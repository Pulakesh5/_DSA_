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
    #define pi pair<long, long>

    int averageNode=0;
    
    pi traverse(TreeNode* root)
    {
        if(!root)
            return {0,0};
        pi leftTree = traverse(root->left);
        pi rightTree = traverse(root->right);
        long count = leftTree.first+rightTree.first+1;
        long sum = leftTree.second+rightTree.second+root->val; 
        if(sum/count == root->val)
            averageNode++;
        return { count, sum};
    }
    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return averageNode;
    }
};
