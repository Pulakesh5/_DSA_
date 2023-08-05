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
    map<pair<int,int>, vector<TreeNode*>> dp;
    vector<TreeNode*> rec(int start, int end)
    {
        if(start>end)
            return {nullptr};
        if(dp.find({start,end})!=dp.end())
            return dp[{start,end}];
        vector<TreeNode*> ans, leftSubTree, rightSubTree;
        TreeNode* root;
        for(int i=start; i<=end; i++)
        {
            
            leftSubTree = rec(start, i-1);
            rightSubTree = rec(i+1, end);
            // cout<<"root is "<<i<<endl;
            for(auto leftNode:leftSubTree)
            {
                for(auto rightNode:rightSubTree)
                {
                    // cout<<"{";
                    // if(leftNode)
                    //     cout<<leftNode->val<<" ";
                    // else
                    //     cout<<"NULL ";
                    // if(rightNode)
                    //     cout<<rightNode->val;
                    // else
                    //     cout<<"NULL";
                    // cout<<"}, ";
                    root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    ans.push_back(root);
                }
            }
            // cout<<endl;
        }
        return dp[{start,end}] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)    
            return vector<TreeNode*>();
        vector<TreeNode*> ans = rec(1,n);
        return ans;
    }
};
