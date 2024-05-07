class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here

        int len = 0;
        Node* auxHead = head;
        while(auxHead!=nullptr)
        {
            len++;
            auxHead = auxHead->next;
        }
        if(head==nullptr || head->next==nullptr || len==k)
            return head;
        // cout<<len<<endl;
        Node *head1 = nullptr, *head2;
        Node *prev;
        auxHead = head;
        while(k--)
        {
            prev = auxHead;
            auxHead = auxHead->next;
        }
        // cout<<prev->data<<endl;
        // cout<<auxHead->data<<endl;
        prev->next = nullptr;
        head1 = auxHead;
        while(auxHead!=nullptr)
        {
            prev = auxHead;
            auxHead = auxHead->next;
        }
        // cout<<prev->data<<" "<<head1<<endl;
        prev->next = head; 
        return head1;
    }
};
