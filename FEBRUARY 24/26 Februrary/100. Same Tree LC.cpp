class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p==nullptr&&q!=nullptr) || (p!=nullptr && q==nullptr))
            return false;
        if(p==nullptr && q==nullptr)
            return true;
        return ((p->val==q->val) && isSameTree(p->left,q->left)&&isSameTree(p->right, q->right));
    }
};
