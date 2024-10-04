class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // code here
        Node *curr = head, *prev = NULL, *nex;
        while (curr != NULL) {
            nex = curr->next;
      
            curr->next = prev;
      
            prev = curr;
            curr = nex;
        }
        return prev->next;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        // code here
        if(head->data == key){
           Node* hh = head;
           while(hh->next != head) hh = hh->next;
           
           hh->next = head->next;
           return head->next;
        }
        // The case in which the value of the head doesn't matches the key value.
        Node* pp = head;
        Node* loop = head->next;
        while(loop != head){
            if(loop->data == key){
                pp->next = loop->next;
                return head;
            }
            loop = loop->next;
            pp = pp->next;
        }
        
        return head;
    }
};
