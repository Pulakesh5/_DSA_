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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr || root2 == nullptr)
            return root1 == root2;
        return (root1->val == root2->val) && ((flipEquiv(root1->right, root2->right) && flipEquiv(root1->left, root2->left)) || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)));
    }
};

// Tree1
//         0
//     2       1
// 4       3       5
//     6       7

// Tree2 
//         0
//     2         1
// 4       3           5
//             6   7
