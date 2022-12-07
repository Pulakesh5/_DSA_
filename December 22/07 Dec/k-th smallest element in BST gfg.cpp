class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        dfs(root,K);
        return ans;
    }
private:
    int ans=-1;
    
    void dfs(Node *root, int &K)
    {
        if(!root) return;
        dfs(root->left,K);
        K--;
        if(K==0){
            ans=root->data;
            return;
        }
        dfs(root->right,K);
    }
};
