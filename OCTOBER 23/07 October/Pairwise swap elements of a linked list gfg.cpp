class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        if(!head || head->next == NULL)
            return head;
        
        struct Node* nextHead = head->next, *nextToNext = head->next->next;
        nextHead->next = head;
        head->next = pairWiseSwap(nextToNext);
            
        return nextHead;
    }
};
