Node *removeDuplicates(Node *head)
{
 // your code goes here
    Node* uniqueLL = new Node(-1);
    Node* root = uniqueLL;
    int prev = -1;
    while(head)
    {
        if(head->data != prev)
        {
            prev = head->data;
            root->next = head;
            root = head;
        }
        head = head->next;
    }
    root->next = NULL;
    return uniqueLL->next;
}
