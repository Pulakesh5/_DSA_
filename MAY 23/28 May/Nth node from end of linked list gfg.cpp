    int getNthFromLast(Node *head, int n)
    {
           // Your code here
           int len = 0;
           Node* root = head;
           while(root)
           {
               len++;
               root = root->next;
           }
           if(len<n) return -1;
           root = head;
           int i = 0;
           while(i<(len-n))
           {
               i++;
               root = root->next;
           }
           return root->data;
    }
