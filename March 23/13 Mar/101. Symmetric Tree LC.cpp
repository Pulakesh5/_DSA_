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
    bool check(vector<int> &level)
    {
        //cout<<" check called "<< level.size()<< endl;

        if(level.size()%2) return false;
        int n=level.size();
        for(int i=(n/2)-1,j=(n/2); i>=0 ;i--,j++)
        {
            //cout<<i<<" "<<j<<" : "<<level[i]<<" , "<<level[j]<<"[ "<<(level[i]!=level[j])<<" ]"<<endl;
            if(level[i]!=level[j]) 
                return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        
        int qs;
        TreeNode* node;

        vector<int> level={root->val};
        while(!q.empty())
        {
            if(level.size()!=1 && !check(level))
                return false;
            qs = q.size();
            level.clear();

            for(int i=0;i<qs;i++)
            {
                node = q.front();
                q.pop();

                if(!(node->left)) level.push_back(INT_MIN);
                else
                {
                    level.push_back(node->left->val);
                    q.push(node->left);
                }

                if(!(node->right)) level.push_back(INT_MIN);
                else
                {
                    level.push_back(node->right->val);
                    q.push(node->right);
                }
            }
        }
        return true;
    }
};
