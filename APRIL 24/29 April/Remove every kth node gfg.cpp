class Solution {
    public:
    Node* deleteK(Node *head,int K){
        if(K==1)
            return nullptr;
      //Your code here
        K--;
        Node *root = head, *prev;
        while(root!=nullptr)
        {
            for(int i=0; i<K && root; i++)
            {
                prev = root;
                root = root->next;
            }  
            if(root)
            {
                prev->next = root->next;
                root = root->next;
            }
        }
        
        return head;
        
    }
};
