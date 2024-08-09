class Solution {
  public:
    pair<int, bool> check(Node* root)
    {
        if(root==nullptr)
            return {0,true};
        pair<int,bool> left = check(root->left);
        pair<int,bool> right = check(root->right);
        
        if(root->left == nullptr && root->right==nullptr)
            return {root->data, true};
        else if(left.first+right.first == root->data)
            return {2*root->data, left.second & right.second};
        else
            return {-1, false};
    }
    bool isSumTree(Node* root) {
        // Your code here
        pair<int,bool> ans = check(root);
        return ans.second;
    }
};
