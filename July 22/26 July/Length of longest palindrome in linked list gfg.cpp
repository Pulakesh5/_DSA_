int match(Node *p1, Node*p2){
    int length=0;
    while(p1 && p2 && p1->data==p2->data)
    {
        length+=2;
        p1=p1->next;
        p2=p2->next;
    }
    return length;
}
int maxPalindrome(Node *head)
{

    Node *curr=head,*prev=NULL, *next;
    int oddLength=0,evenLength=1;
    while(curr->next){
        next=curr->next;
        curr->next=prev;
        
        evenLength=max(evenLength,match(curr,next));
        oddLength=max(oddLength,1+match(prev,next));
        
        prev=curr;
        curr=next;
    }
    
    return max(oddLength, evenLength);
}
