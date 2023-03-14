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
    long long pathSum=0;
    int sumNumbers(TreeNode* root) {
        int sumTillNow=0;
        process(root, sumTillNow);
        return pathSum;
    }
    void process(TreeNode* root, int sum)
    {
        if(!root) return;
        if(!root->left && !root->right){
            pathSum+=(sum*10+root->val);
            return;
        }

        process(root->left,sum*10+root->val);
        process(root->right,sum*10+root->val);
    }
};
