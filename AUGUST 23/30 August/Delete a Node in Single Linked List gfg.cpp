Node* deleteNode(Node *head,int x)
{
    //Your code here
    if(!head)
        return head;
    if(x == 1)
        return head->next;
    Node* root = head->next, *prev=head;
    int length = 2;
    while(root && length<x)
    {
        prev = root;
        root = root->next;
        length++;
    }
    if(length==x)
        prev->next = root->next;
    return head;
}
