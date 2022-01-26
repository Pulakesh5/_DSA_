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
// Try Optimizing the merge function
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2,ans;
        Inorder(root1,v1);
        Inorder(root2,v2);
        merge(v1,v2,ans);
        return ans;
    }
    void Inorder(TreeNode *root, vector<int> &v){
        if(root==NULL) return;
        Inorder(root->left, v);
        v.push_back(root->val);
        Inorder(root->right, v);
    }
    void merge(vector<int> &v1,vector<int> &v2, vector<int> &ans)
    {
        int n1=v1.size(), n2=v2.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(v1[i]<v2[j])
                ans.push_back(v1[i++]);
            else
                ans.push_back(v2[j++]);
        }
        //cout<<i<<" "<<j<<endl;
        //cout<<n1<<" "<<n2<<endl;
        while(i<n1)
            ans.push_back(v1[i++]);
        while(j<n2)
            ans.push_back(v2[j++]);
        
    }
};
