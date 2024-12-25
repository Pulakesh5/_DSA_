class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            int qs = q.size(), rowMax = INT_MIN;
            for(int i=0; i<qs; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->val > rowMax)
                    rowMax = node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(rowMax);
        }
        return ans;
    }
};d
