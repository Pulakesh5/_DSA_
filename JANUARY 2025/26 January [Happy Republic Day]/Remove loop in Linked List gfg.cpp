class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        Node *slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                slow = head;
                Node *prev = fast;;
                while(slow != fast)
                {
                    slow = slow->next;
                    // prev = fast;
                    fast = fast->next;
                }
                while(fast->next!=slow)
                    fast = fast->next;
                fast->next = NULL;
                // prev->next = nullptr;
            }
        }
    }
};
