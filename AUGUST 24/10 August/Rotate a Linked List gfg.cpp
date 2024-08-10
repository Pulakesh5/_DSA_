class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        // Your code here
        int len = 0;
        Node *root = head, *last;
        while(root)
        {
            len++;
            last = root;
            root = root->next;
        }
        k = k%len;
        if(k==0)
            return head;
        root = head;
        while(--k)
            root = root->next;
        
        Node* ans = root->next;
        last->next = head;
        root->next = nullptr;
        return ans;
    }
};
