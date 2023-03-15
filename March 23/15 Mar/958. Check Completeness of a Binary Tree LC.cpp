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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        
        int qs;
        bool flag=false;
        TreeNode* node;

        while(!q.empty())
        {
            qs = q.size();
            for(int i=0;i<qs;i++)
            {
                node = q.front();
                q.pop();

                if(node->left)
                {
                    if(flag) return false;
                    q.push(node->left);

                }
                else
                    flag = true;
                
                if(node->right)
                {
                    if(flag) return false;
                    q.push(node->right);
                }
                else
                    flag = true;
                
            }
        }
        return true;
    }
};
