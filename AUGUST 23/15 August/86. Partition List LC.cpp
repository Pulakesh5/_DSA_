class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> l, ge;
        ListNode* root = head;
        while(root)
        {
            if(root->val<x)
                l.push_back(root->val);
            else
                ge.push_back(root->val);
            root = root->next;
        }
        root = head;
        int i = 0, j = 0;
        while(root)
        {
            if(i<l.size())
                root->val = l[i++];
            else
                root->val = ge[j++];
            root = root->next;
        }
        return head;
    }
};
