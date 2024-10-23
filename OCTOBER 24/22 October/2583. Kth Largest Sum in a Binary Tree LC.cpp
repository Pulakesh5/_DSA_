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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levelSums;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int qsize = q.size();
            long long levelSum = 0;
            for(int i=0; i<qsize; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                levelSum += front->val;
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            levelSums.push_back(levelSum);
        }
        if(levelSums.size()<k)
            return -1;
        sort(levelSums.begin(), levelSums.end());
        return levelSums[levelSums.size()-k];
    }
};
