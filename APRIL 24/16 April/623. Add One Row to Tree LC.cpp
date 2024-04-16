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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        depth--;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        int qsize;
        while(--depth)
        {
            qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        qsize = q.size();
        TreeNode *lChild, *rChild;
        for(int i=0; i<qsize; i++)
        {
            node = q.front();
            q.pop();
            lChild = new TreeNode(val,node->left,nullptr);
            rChild = new TreeNode(val,nullptr,node->right);
            node->left = lChild;
            node->right = rChild;
        }

        return root;
    }
};
