class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        if(root->left==nullptr)
            return root->data;
        return minValue(root->left);
    }
};
