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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool flag=false;
        int qs;
        vector<vector<int>> traversal;

        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            qs=q.size();
            vector<int> row;
            for(int i=0;i<qs;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                row.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag)
                reverse(row.begin(), row.end());
            traversal.push_back(row);
            flag=(flag?false:true);
        }
        return traversal;
    }
};
