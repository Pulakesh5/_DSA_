//Solution 0:
class Solution {
public:
    void fun(TreeNode *root,vector<int> &vec){
        if(!root) return;       
        fun(root->left, vec);
        vec.push_back(root->val);
        fun(root->right, vec);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        fun(root,vec);
        return vec[k-1];
    }
};

//Solution 1:
class Solution {
public:
    int ans=0;
    void fun(TreeNode *root, int &k){
        if(!root) return;       
        fun(root->left,k);
        if(--k==0){
            ans=root->val;
            return;
        }
        fun(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        fun(root,k);
        return ans;
    }
};
