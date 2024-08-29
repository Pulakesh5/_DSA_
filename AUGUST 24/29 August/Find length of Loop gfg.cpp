class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        if(head==nullptr || head->next==nullptr)
            return 0;
        Node *slowPtr = head, *fastPtr = head;
        while(fastPtr!=nullptr && fastPtr->next!=nullptr)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(slowPtr == fastPtr)
            {
                slowPtr = slowPtr->next;
                int length = 1;
                while(slowPtr!=fastPtr)
                {
                    slowPtr = slowPtr->next;
                    length++;
                }
                return length;
            }
        }
        return 0;
        
    }
};
