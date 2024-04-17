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
private:
    string lexSmallestPath = string(8501,(char)('a'+26));
    void traverse(TreeNode* root, string path)
    {
        path.push_back('a'+root->val);
        if(root->left==nullptr && root->right==nullptr)
        {
            string rev = path;
            reverse(rev.begin(), rev.end());
            if(rev<lexSmallestPath)
                lexSmallestPath = rev;
            path.pop_back();
            return;
        }
        
        if(root->left)
            traverse(root->left, path);
        
        if(root->right)
            traverse(root->right, path);
        
        path.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        traverse(root, path);
        return lexSmallestPath;
    }
};
