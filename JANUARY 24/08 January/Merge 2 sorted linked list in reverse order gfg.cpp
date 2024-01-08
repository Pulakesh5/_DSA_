class Solution
{
    public:
    struct Node* reverse(struct Node* head)
    {
        if(!head || !(head->next))
            return head;
        struct Node *prev=nullptr,*curr=head, *next=head->next, *tmp;
        while(curr)
        {
            
            curr->next = prev;
            prev = curr;
            curr = next;
            if(!curr)
                return prev;
            next = curr->next;
        }
        return prev;
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        struct Node* mergeHead, *head=newNode(-1);
        mergeHead = head;
        while(node1!=NULL || node2!=NULL)
        {
            if(node1==nullptr)
            {
                // cout<<node2->data<<endl;
                head->next = newNode(node2->data);
                node2 = node2->next;
            }
            else if(node2==nullptr)
            {
                // cout<<node1->data<<endl;
                head->next = newNode(node1->data);
                node1 = node1->next;
            }
            else if(node1->data >= node2->data)
            {
                // cout<<node1->data<<" "<<node2->data<<endl;
                head->next = newNode(node2->data);
                node2 = node2->next;
            }
            else
            {
                // cout<<node1->data<<" "<<node2->data<<endl;
                head->next = newNode(node1->data);
                node1 = node1->next;
            }
            head = head->next;
        }
        return reverse(mergeHead->next);
        // return mergeHead->next;
    }  
};
