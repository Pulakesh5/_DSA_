class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //Your code here
        Node* newNode = new Node(data);
        Node* root = head;
        if(!head)
        {
            newNode->next = newNode;
            return newNode;
        }
        else if(head->data>data){
            while(root->next != head)
                root = root->next;
            newNode->next = root->next;
            root->next = newNode;
            return newNode;
        }
        else
        {
            while(root->next!=head && root->next->data<data)
                root = root->next;
            newNode->next = root->next;
            root->next = newNode;
        }
        
        return head;
    }
};
