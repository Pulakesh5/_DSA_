class Solution {
  public:
    void traverse(Node* root, vector<int> &v)
    {
        if(root == nullptr)
            return;
        traverse(root->left, v);
        v.push_back(root->data);
        traverse(root->right, v);
    }
    bool findTarget(Node *root, int target) {
        // your code here.
        vector<int> v;
        traverse(root, v);
        int left = 0, right = v.size()-1;
        while(left<right)
        {
            if(v[left]+v[right]<target)
                left++;
            else if(v[left]+v[right]>target)
                right--;
            else
                return true;
        }
        return false;
    }
};
