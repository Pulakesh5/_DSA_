class Solution {
  public:
    // Function to find largest subtree sum.
    int findLargestSubtreeSum(Node* root)
    {
        //Write your code here
        int ans=INT_MIN;
        dfs(root,ans);
        return ans;
    }
    
    int dfs(Node* root, int &ans)
    {
        if(!root) return 0;
        
        int sum=root->data +
            dfs(root->left,ans) +
            dfs(root->right,ans);
        
        ans=max(sum,ans);
        
        return sum;
    }
};
