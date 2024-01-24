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
    void traverse(TreeNode* root, vector<int> digitCount, int &pathCount)
    {
        if(root==nullptr)
            return;
        digitCount[root->val]++;
        if(root->right==nullptr && root->left==nullptr)
        {
            int oddCount=0;
            for(int i=1; i<10; i++)
            {
                if(digitCount[i]%2)
                    oddCount++;
            }
            if(oddCount<=1)
                pathCount++;
        }
        else
        {
            traverse(root->left, digitCount, pathCount);
            traverse(root->right, digitCount, pathCount);   
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> digitCount(10);
        int pseudoPalPath = 0;
        traverse(root, digitCount, pseudoPalPath);
        return pseudoPalPath;
    }
};
