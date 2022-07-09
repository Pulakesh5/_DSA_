class Solution{
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node* addPolynomial(Node *p1, Node *p2)
    {
        //Your code here
        Node *ans, *head = new Node(-1,-1);
        ans=head;
        int i=0;
        while(p1 && p2){
            if(p1->pow > p2->pow){
                head -> next= new Node(p1->coeff,p1->pow);
                head=head->next;
                p1=p1->next;
            }
            else if(p2->pow > p1->pow){
                head -> next = new Node(p2->coeff,p2->pow);
                head=head->next;
                p2=p2->next;
            }
            else { //while(p1->pow == p2->pow)
                head -> next = new Node(p1->coeff + p2->coeff,p1->pow);
                head=head->next;
                p1=p1->next;
                p2=p2->next;
            }
        }
        
        while(p1){
            head -> next = new Node(p1->coeff,p1->pow);
            head=head->next;
            p1=p1->next;
        }
        while(p2){
            head -> next = new Node(p2->coeff,p2->pow);
            head=head->next;
            p2=p2->next;
        }
        
        return ans->next;
    }
};
