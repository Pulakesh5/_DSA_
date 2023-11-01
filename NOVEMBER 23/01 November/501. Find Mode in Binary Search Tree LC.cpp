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
    int last=INT_MIN;
    int lastCount=0, maxCount=0;
    vector<int> modes;
    void traverse(TreeNode* root)
    {
        if(!root)
            return;
        traverse(root->left);
        if(last==INT_MIN)
        {
            last = root->val;
            lastCount = 1;
            maxCount = 1;
            modes.push_back(root->val);
        }
        else
        {
            if(last==(root->val))
            {
                lastCount++;
            }
            else
            {
                last = root->val;
                lastCount = 1;
            }
            if(lastCount>=maxCount)
            {
                if(lastCount>maxCount)
                    modes.clear();
                modes.push_back(root->val);
                maxCount = lastCount;
            }
        }
        traverse(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        
        traverse(root);
        if(lastCount>=maxCount && (modes.empty() || modes.back()!=last))
            modes.push_back(last);
        return modes;
    }
};
