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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxLevelSum = INT_MIN, levelSum = 0, maxLevel = -1, level = 1;
        while(!q.empty())
        {
            int qsize = q.size();
            levelSum = 0;
            while(qsize--)
            {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(levelSum>maxLevelSum)
            {
                maxLevelSum = levelSum;
                maxLevel = level;
            }
            level++;
        }
        return maxLevel;
    }
};
