class Solution {
  public:
    void traverse(Node* root, int val, long long &sum)
    {
        if(!root)
            return;
            
        if(root->left == nullptr && root->right==nullptr)
        {
            sum += (val*10 + root->data);
            return;
        }
        
        traverse(root->left, val*10+root->data, sum);
        traverse(root->right, val*10+root->data, sum);
    }
    int treePathsSum(Node *root) {
        // code here.
        int val = root->data;
        long long sum = 0;
        traverse(root, 0, sum);
        return sum;
    }
};
