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
    TreeNode* LCA(TreeNode *root, int lChild, int rChild)
    {
        if(root == nullptr)
            return nullptr;
        if(root->val==lChild || root->val==rChild)
            return root;
        TreeNode *lRoot = LCA(root->left, lChild, rChild);
        TreeNode *rRoot = LCA(root->right, lChild, rChild);
        if(lRoot == nullptr)
            return rRoot;
        if(rRoot == nullptr)
            return lRoot;
        return root;
    }
    void find(TreeNode* root, int start, string &path, string &finalPath)
    {
        if(root == nullptr)
            return;
        if(root->val == start)
        {
            finalPath = path;
            return;
        }
        if(root->right)
        {
            path.push_back('R');
            find(root->right, start, path, finalPath);
            path.pop_back();
        }
        if(root->left)
        {
            path.push_back('L');
            find(root->left, start, path, finalPath);
            path.pop_back();
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // TreeNode* ancestor = LCA(root, startValue, destValue);
        string path = "", startPath = "", destPath =  "";
        find(root, startValue, path, startPath);
        find(root, destValue, path, destPath);
        int common = 0, minLen = min(startPath.size(), destPath.size());
        while(common<minLen && startPath[common]==destPath[common])
            common++;
        
        int i=common, startPathLen = startPath.size(), destPathLen = destPath.size();
        string direction((startPathLen-common), 'U');
        while(i<destPathLen)
        {
            direction.push_back(destPath[i]);
            i++;
        }
        return direction;
    }
};
