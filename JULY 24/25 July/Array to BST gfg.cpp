class Solution {
  public:
    Node* makeBST(vector<int> &nums, int l, int r)
    {
        if(l>r)
            return nullptr;
        int mid = (l+r)/2;
        Node* treeNode = new Node(nums[mid]);
        treeNode->left = makeBST(nums, l, mid-1);
        treeNode->right = makeBST(nums, mid+1, r);
        return treeNode;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        int N = nums.size();
        return makeBST(nums, 0, N-1);
    }
};
