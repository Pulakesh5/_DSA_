class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        Node *slow = head, *fast = head->next;
        while(slow && fast)
        {
            slow = slow->next;
            fast = fast->next ? fast->next->next : nullptr;
            if(slow==fast)
                return true;
        }
        return false;
    }
};
