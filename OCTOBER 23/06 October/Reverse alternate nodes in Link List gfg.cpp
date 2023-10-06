class Solution
{
    public:
    struct Node *reverse(struct Node *head)
    {
        struct Node *prev = NULL, *curr = head, *end;
        while(curr != NULL)
        {
            end = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = end;
        }
        return prev;
    }
    void rearrange(struct Node *odd)
    {
        if(odd -> next == NULL) return;
        struct Node *t1 = odd, *t2 = odd -> next, *t3 = odd -> next;
        while(t1 -> next != NULL && t1 -> next -> next != NULL)
        {
            t1 -> next = t1 -> next -> next;
            t1 = t1 -> next;
            if(t2 -> next != NULL && t2 -> next -> next != NULL)
            {
                t2 -> next = t2 -> next -> next;
                t2 = t2 -> next;
            }
        }
        t2 -> next = NULL;
        t3 = reverse(t3);
        t1 -> next = t3;
    }
};
