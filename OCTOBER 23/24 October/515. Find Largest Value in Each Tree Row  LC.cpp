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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        int rowMax = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int qsize;
        vector<int> ans;
        while(!q.empty())
        {
            qsize = q.size();
            rowMax = INT_MIN;
            for(int i=0; i<qsize; i++)
            {
                TreeNode* root = q.front();
                q.pop();
                rowMax = max(rowMax, root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            ans.push_back(rowMax);
        }
        return ans;
    }
    
};
