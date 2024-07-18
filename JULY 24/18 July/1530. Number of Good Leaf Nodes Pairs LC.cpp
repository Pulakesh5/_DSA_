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
int pairCount = 0;
public:
    vector<int> dfs(TreeNode* root, int distance)
    {
        vector<int> dist;
        if(root==nullptr)
            return dist;
        if(root->left == nullptr && root->right == nullptr)
            return {1};
        vector<int> left = dfs(root->left, distance);
        vector<int> right = dfs(root->right, distance);

        for(int ldist:left)
            for(int rdist:right)
                if(ldist+rdist<=distance)
                    pairCount++;

        for(int &ldist:left)
        {
            ldist++;
            dist.push_back(ldist);
        }

        for(int &rdist:right)
        {
            rdist++;
            dist.push_back(rdist);
        }

        return dist;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return pairCount;      

    }
};
