class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        struct Node *vowelHead = new Node('$'), *consnHead = new Node('$');
        struct Node *head1 = vowelHead, *head2 = consnHead;
        struct Node* root = head;
        char ch;
        while(root!=nullptr)
        {
            ch = root->data;
            if(ch=='a' || ch=='e' || ch == 'i' || ch=='o' || ch=='u')
            {
                head1->next = new Node(ch);
                head1 = head1->next;
            }
            else
            {
                head2->next = new Node(ch);
                head2 = head2->next;
            }
            root = root->next;
        }
        if(vowelHead->next==nullptr)
            return consnHead->next;
        else
        {
            head1->next = consnHead->next;
            return vowelHead->next;
        }
    }
};
