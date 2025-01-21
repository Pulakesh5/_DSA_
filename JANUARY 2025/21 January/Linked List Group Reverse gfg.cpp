class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(k==1)
            return head;
        
        Node *prev = NULL, *curr = head, *nxt = NULL;
        Node *currSegmentTail = NULL, *prevSegmentTail = NULL, *root = NULL;
        int count, first = 1;
        while(curr)
        {
            count = k;
            currSegmentTail = curr;
            while(curr && count)
            {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
                count--;
            }
            if(first)
            {
                root = prev;
                first = 0;
            }
            else
            {
                prevSegmentTail-> = prev; 
            }
            prevSegmentTail = currSegmentTail;
        }
        prevSegmentTail->next=NULL;
        return root;
    }
};
