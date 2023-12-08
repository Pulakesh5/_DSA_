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
    string makeString(int n)
    {
        if(n==0)
            return "0";
        string str = "";
        int num = n;
        if(num<0)
            num = num * -1;
        while(num)
        {
            str.push_back(num%10+'0');
            num = num/10;
        }
        if(n<0)
            str.push_back('-');
        reverse(str.begin(), str.end());
        return str;
    }
    string tree2str(TreeNode* root) {
        string ans = "";
        if(!root)
            return ans;
        
        string leftStr = tree2str(root->left);
        string rightStr = tree2str(root->right);
        
        ans += makeString(root->val);

        if(leftStr.size()==0 && rightStr.size()==0)
            return ans;

        if(leftStr.size()>0)
        {
            ans.push_back('(');
            ans+=leftStr;
            ans.push_back(')');
        }
        
        if(leftStr.size()==0 && rightStr.size()!=0)
            ans+="()";
        if(rightStr.size())
        {
            ans.push_back('(');
            ans+=rightStr;
            ans.push_back(')');
        }
        return ans;
    }
};
