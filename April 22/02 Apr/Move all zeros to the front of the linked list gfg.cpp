//User function Template for C++
/* Linked List Node structure
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
// Move Zeros to the front of the list
void moveZeroes(struct Node **head)
{
    Node *start= *head;
    
    vector<int> arr;
    int zero=0;
    while(start){
        if(start->data){
            arr.push_back(start->data);   
        }
        else
        zero++;
        start=start->next;
    }
    start=*head;
    while(zero--){
       start->data=0;
       start=start->next;
    }
    int size=arr.size(),i=0;
    while(size--){
        start->data=arr[i++];
        start=start->next;
    }
}
/////////////////////////////////////////////////
void moveZeroes(struct Node **head)
{
    Node *temp=(*head)->next,*prev=(*head);
    
    while(temp){
        if(temp->data==0){
            Node *curr=temp;
            temp=temp->next;
            
            prev->next=temp;
            curr->next=(*head);
            (*head)=curr;
        }
        else{
            prev=temp;
            temp=temp->next;
        }
    }
}
