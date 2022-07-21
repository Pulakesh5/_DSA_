class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return head;
        ListNode *root=head;
        int n=0;
        vector<int> v;
        while(root){
            n++;
            //if(n>=left && n<=right) 
            v.push_back(root->val);
            root=root->next;
        }
        reverse(v.begin()+left-1,v.begin()+right);
        root=head;
        for(int i=1;i<=n;i++){
            if(i>=left && i<=right){
                root->val=v[i-1];
                v.pop_back();
            }
            root=root->next;
        }
        return head;
    }
};
