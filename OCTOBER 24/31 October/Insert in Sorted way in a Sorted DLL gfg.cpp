class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        Node *currNode = head, *prev = nullptr;
        Node *newNode = getNode(x);
        if(head->data>=x)
        {
            
            newNode->next = head;
            head->prev = newNode;
            return newNode;
        }
        while(currNode && currNode->data<x)
        {
            prev = currNode;
            currNode = currNode->next;
        }
        
        newNode->prev = prev;
        newNode->next = currNode;
        
        prev->next = newNode;
        if(currNode)
            currNode->prev = newNode;
            
        return head;
        
    }
};
