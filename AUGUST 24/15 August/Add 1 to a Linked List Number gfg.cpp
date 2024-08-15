class Solution {
  public:
    int add(Node* head, int &carry)
    {
        if(head== nullptr)
            return carry;
        // cout<<carry<<" received by "<<head->data<<endl;
        carry = add(head->next, carry);
        
        head->data += carry;
        carry = head->data/10;
        head->data%10;
        
        // cout<<carry<<" returned by "<<head->data<<endl;
        return carry;
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        int carry = 1;
        carry = add(head, carry);
        if(carry)
        {
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};
