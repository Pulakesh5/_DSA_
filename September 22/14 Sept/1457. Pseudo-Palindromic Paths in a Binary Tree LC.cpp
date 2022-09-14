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
    vector<int> digCount;
    void _count(TreeNode* root, int &count)
    {
        digCount[root->val]++;
        if(root->left)
            _count(root->left,count);
        if(root->right)
            _count(root->right,count);
        if(!(root->left) && !(root->right))
        {
            int oddCount=0;
            for(int i=1;i<=9;i++)
            {
                if(digCount[i]&1) 
                    oddCount++;
            }
            if((oddCount<=1))
            {
                count++;
            }
        }
        digCount[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        for(int i=0;i<=9;i++) digCount.push_back(0);
        int count=0;
        _count(root,count);
        return count;
    }
};
