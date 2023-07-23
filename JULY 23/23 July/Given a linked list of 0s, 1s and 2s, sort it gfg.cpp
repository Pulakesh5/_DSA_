class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* root = head;
        int zero = 0, one = 0, two = 0;
        while(root)
        {
            if(root->data == 0)
                zero++;
            else if(root->data == 1)
                one++;
            else
                two++;
            root = root->next;
        }
        root = head;
        while(zero--)
        {
            root->data = 0;
            root = root->next;
        }
        while(one--)
        {
            root->data = 1;
            root = root->next;
        }
        while(two--)
        {
            root->data = 2;
            root = root->next;
        }
        return head;
    }
};
