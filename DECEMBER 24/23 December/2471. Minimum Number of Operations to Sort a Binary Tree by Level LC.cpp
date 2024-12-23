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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int swapCount = 0;
        while(!q.empty())
        {
            int qs = q.size();
            vector<pair<int,int>> v(qs);
            for(int i=0; i<qs; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
                v[i] = {node->val, i};
            }
            sort(v.begin(), v.end());
            vector<bool> vis(qs);
            for(int i=0; i<qs; i++)
            {
                if(vis[i] || v[i].second==i)
                    continue;
                int cycleLength=0, j=i;
                while(!vis[j])
                {
                    cycleLength++;
                    vis[j] = true;
                    j = v[j].second;
                }
                swapCount += max(cycleLength-1, 0);
            }
        }
        return swapCount;
    }
};
