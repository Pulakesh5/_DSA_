class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        Node *slow = head, *fast=head;
        while(slow && fast){
            slow=slow->next;
            if(fast->next) fast = fast->next->next;
            else
                return false;
            
            if(slow==fast) return true;
        }
        return false;
    }
};
