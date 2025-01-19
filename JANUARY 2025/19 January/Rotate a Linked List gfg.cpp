class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        Node *curr = head, *nxt, *left, *prev;
        int len = 0;
        while(curr)
        {
            len++;
            curr = curr->next;
        }
        k = k%len;
        if(k==0)
            return head;
            
        curr = head;
        while(curr)
        {
            k--;
            if(k==0)
            {
                left = curr->next;
                prev = curr;
            }
            curr = curr->next;
        }
        Node *ans = left;
        prev->next = nullptr;
        while(left->next)
            left = left->next;
        left->next = head;
        return ans;
    }
};
