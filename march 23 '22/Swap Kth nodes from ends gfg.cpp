Node *swapkthnode(Node* head, int n, int k)
{
    if(k>n) return head;
    
    Node* arr[n];
    Node *ptr=head;
    int i=0;
    while(ptr){
        arr[i++]=ptr;
        ptr=ptr->next;
    }
    swap(arr[k-1],arr[n-k]);
    
    ptr=head;
    int temp=n;
    while(temp--){
        Node *curr=ptr;
        ptr=ptr->next;
        curr->next=NULL;
    }
    
    head=arr[0];
    ptr=head;
    i=1;
    n--;
    
    while(n--){
        ptr->next=arr[i++];
        ptr=ptr->next;
    }
    return head;
    
}
