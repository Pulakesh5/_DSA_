/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int n=0;
        ListNode* root=head;
        vector<int> vec;
        while(root)
        {
            n++;
            vec.push_back(root->val);
            root=root->next;
        }
        int l=0,r=n-1;
        return makeBST(vec,l,r);
    }
    TreeNode* makeBST(vector<int> &vec, int l, int r)
    {
        if(l>r) return NULL;

        int mid=(l+r)/2;

        TreeNode* root = new TreeNode;
        root->val=vec[mid];
        root->left = makeBST(vec,l,mid-1);
        root->right = makeBST(vec,mid+1,r);
        return root;

    }
};
