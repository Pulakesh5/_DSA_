class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        if(head->next == nullptr)
            return head->data;
        Node *slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            if(fast->next)
                fast = fast->next->next;
            else
                fast = nullptr;
        }
        
        return slow->data;
    }
};
