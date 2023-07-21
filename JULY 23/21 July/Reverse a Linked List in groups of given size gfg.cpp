struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node *prev = NULL, *curr = head, *next = NULL;
        struct node *currSegmentTail = NULL, *prevSegmentTail = NULL, *root = NULL;
        int count, first = 1;
        while(curr)
        {
            count = k;
            currSegmentTail = curr;
            while(curr && count)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count--;
            }
            if(first)
            {
                root = prev;
                first = 0;
            }
            else
            {
                prevSegmentTail->next = prev; 
            }
            prevSegmentTail = currSegmentTail;
        }
        prevSegmentTail->next=NULL;
        return root;
    }
