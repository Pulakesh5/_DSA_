class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node *prev = nullptr, *curr = head, *nxt;
        while(curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};
