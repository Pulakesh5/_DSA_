class Solution
{
    public:
    //Function to remove a loop in the linked list.
    
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *slow = head, *fast=head;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast){
                _removeLoop(slow,head);
                //return true;
            }
        }
        return;
        //return false;
    }
    void _removeLoop(Node *loopNode, Node *head){
        Node* ptr1=loopNode, *ptr2=loopNode;
        int loopLength=1;
        while(ptr1->next != ptr2)
        {
            ptr1 = ptr1->next;
            loopLength++;
        }
        ptr1=head;
        
        ptr2=head;
        for(int i=0;i<loopLength;i++)
            ptr2 = ptr2->next;
        
        while (ptr2 != ptr1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        while(ptr2->next != ptr1)
        {
            ptr2 = ptr2->next;
        }
        ptr2->next=NULL;
        
    }
};
