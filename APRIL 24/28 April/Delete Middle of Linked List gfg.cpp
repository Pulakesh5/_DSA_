class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        // Your Code Here
        int len = 0;
        Node* root = head;
        while(root)
        {
            root= root->next;
            len++;
        }
        len = (len/2);
        Node* prev = nullptr;
        root = head;
        while(len--)
        {
            prev = root;
            // cout<<root->data<<endl;
            root = root->next;
        }
        prev->next = root->next;
        return head;
  
    }
};
