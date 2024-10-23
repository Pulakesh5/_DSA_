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
    TreeNode* replaceValueInTree(TreeNode* root) {
        map<TreeNode*, int> parentSum;
        vector<long long> levelSums;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        while(!q.empty())
        {
            int qsize = q.size();
            long long levelSum = 0;
            for(int i=0; i<qsize; i++)
            {
                TreeNode* node = q.front().first;
                TreeNode* parent = q.front().second;
                q.pop();
                levelSum += node->val;
                if(parent)
                    parentSum[parent] += node->val;
                if(node->right)
                    q.push({node->right, node});
                if(node->left)
                    q.push({node->left, node});
            }
            levelSums.push_back(levelSum);
        }

        for(auto sum:levelSums)
            cout<<sum<<endl;
        
        int level = 1;
        root->val = 0;
        if(root->right)
            q.push({root->right, root});
        if(root->left)
            q.push({root->left, root});
        
        while(!q.empty())
        {
            int qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                TreeNode* node = q.front().first;
                TreeNode* parent = q.front().second;
                q.pop();
                node->val = levelSums[level] - parentSum[parent];

                if(node->right)
                    q.push({node->right, node});
                if(node->left)
                    q.push({node->left, node});
            }
            level++;
        }
        return root;
    }
};
