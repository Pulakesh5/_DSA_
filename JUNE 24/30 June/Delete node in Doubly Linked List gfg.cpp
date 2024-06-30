class Solution {
  public:
    Node* deleteNode(Node* ListHead, int x) {
        Node* head = ListHead;
        if(x==1)
        {
            head = head->next;
            head->prev = nullptr;
            return head;
        }
        Node *prev, *next;
        int pos = 1;
        while(head!=nullptr && pos<x)
        {
            prev = head;
            head = head->next;
            pos++;
        }
        next = head->next;
        prev->next = next;
        if(next)
            next->prev = prev;
        return ListHead;
    }
};
